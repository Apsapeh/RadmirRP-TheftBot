#include "XLAT_head.h"
#include "mainWindow.h"
#include "Header.h"


using namespace System::Windows::Forms;
using namespace std;

extern bool run_bool;
extern default_res deff_res;
extern set_set s_set;

// Основная функция, из неё запускается транспондер и монтировка
void t_c_func()
{
    while (true)
    {
        if (GetKeyState(VK_F9) < 0)
        {
            Beep(600, 500);
            transponder_function();
        }
        else if (GetKeyState(VK_F8) < 0)
        {
            Beep(600, 500);
            crowbar_function();
        }
        else if (GetKeyState(VK_F10) < 0 && GetKeyState(VK_CONTROL) < 0)
        {
            Application::Exit();
            exit(0);
        }
        else
            Sleep(5);
    }
}


// Функция транспондера
void transponder_function() 
{
    CaptureScreen CaptureSc;

    bool find_stat = false;
    bool out_break = false;

    // Диапазон цвета
    COLORREF min = RGB(s_set.min_r, s_set.min_g, s_set.min_b);
    COLORREF max = RGB(s_set.max_r, s_set.max_g, s_set.max_b);

    int* a;

    while (true)
    {
        if (run_bool)
        {
            // Завершает программу если были нажаты клавиши CTRL + F10 или RCTRL + F10
            if (GetKeyState(VK_F10) < 0 && GetKeyState(VK_CONTROL) < 0)
            {
                Application::Exit();
                exit(0);
            }

            if (GetKeyState(VK_F8) < 0)
                break;

            // Приостанавливает программу если была нажата клавиша F10
            if (GetKeyState(VK_F10) < 0)
            {
                Beep(250, 500);

                while (true)
                {
                    // Продолжает работу программы если была нажата клавиша F9
                    if (GetKeyState(VK_F9) < 0)
                    {
                        Beep(500, 500);
                        break;
                    }                        
                    else if (GetKeyState(VK_F8) < 0)
                    {
                        out_break = true;
                        break;
                    }
                    // Завершает программу если были нажаты клавиши CTRL + F10 или RCTRL + F10
                    else if (GetKeyState(VK_F10) < 0 && GetKeyState(VK_CONTROL) < 0)
                    {
                        Application::Exit();
                        exit(0);
                    }         
                    else
                        Sleep(5);
                }
                if (out_break)
                    break;
            }
            
            // Берёт значения писелей из памяти
            CaptureSc.get_pixel(deff_res.x_trans, deff_res.y_trans, deff_res.width_trans, deff_res.height_trans);

            for (int y = 0; y <= deff_res.height_trans - 1; ++y)
            {
                for (int x = 0; x <= deff_res.width_trans - 1; ++x)
                {
                    a = CaptureSc.info(x, y);
                    COLORREF color = RGB(a[0], a[1], a[2]);

                    if (GetRValue(color) >= GetRValue(min) && GetRValue(color) <= GetRValue(max) &&
                        GetGValue(color) >= GetGValue(min) && GetGValue(color) <= GetGValue(max) &&
                        GetBValue(color) >= GetBValue(min) && GetBValue(color) <= GetBValue(max))
                    {
                        find_stat = true;
                        break;
                    }

                }

                // При нахождении писеля из цветового диапозона жмёт enter и ждёт 0.4 сек
                if (find_stat)
                {
                    //cout << "Push" << endl;
                    keybd_event(VK_RETURN, NULL, NULL, NULL);
                    keybd_event(VK_RETURN, NULL, KEYEVENTF_KEYUP, NULL);
                    Sleep(400);

                    find_stat = false;
                    break;         
                }
            }  
        }
        else
            Sleep(1);
    }
}


// Фунция монтировки
void crowbar_function()
{
    CaptureScreen CaptureSc;

    int finded = 0;
    int max_finded = 0;

    int last_findX = -1;
    int last_findY = -1;

    bool out_break = false;
    bool finded_b = false;

    int findedVoidX = 0;
    int findedVoidY = 0;

    // Диапазон цветов
    COLORREF max = RGB(145, 255, 135);
    COLORREF min = RGB(10, 125, 0);

    int* a;
    while (true)
    {
        if (run_bool)
        {
            // Завершает программу если были нажаты клавиши CTRL + F10 или RCTRL + F10
            if (GetKeyState(VK_F10) < 0 && GetKeyState(VK_CONTROL) < 0)
            {
                Application::Exit();
                exit(0);
            }

            if (GetKeyState(VK_F9) < 0)
                break;

            // Приостанавливает программу если была нажата клавиша F10
            if (GetKeyState(VK_F10) < 0)
            {
                Beep(250, 500);

                while (true)
                {
                    // Продолжает работу программы если была нажата клавиша F9
                    if (GetKeyState(VK_F8) < 0)
                    {
                        Beep(500, 500);
                        break;
                    }                       
                    else if (GetKeyState(VK_F9) < 0)
                    {
                        out_break = true;
                        break;
                    }
                    // Завершает программу если были нажаты клавиши CTRL + F10 или RCTRL + F10
                    else if (GetKeyState(VK_F10) < 0 && GetKeyState(VK_CONTROL) < 0)
                    {
                        Application::Exit();
                        exit(0);
                    }
                    else
                        Sleep(5);
                }
                if (out_break)
                    break;
            }

            if (finded_b == false)
            {
                finded = 0;
                max_finded = 0;

                // Читает значения пикселей
                CaptureSc.get_pixel(deff_res.x_crowbar, deff_res.y_crowbar, deff_res.width_crowbar, deff_res.height_crowbar);

                // Ищет пустой кружок ( в который надо попасть точкой)
                for (int y_ = 0; y_ <= deff_res.height_crowbar - (deff_res.box_size + 1); ++y_)
                {
                    for (int x_ = 0; x_ <= deff_res.width_crowbar - (deff_res.box_size + 1); ++x_)
                    {
                        // Пропускат область где находится замочек
                        if ((y_ >= (deff_res.width_crowbar - deff_res.lock_box_size) / 2 - deff_res.box_size && y_ <= deff_res.width_crowbar - (deff_res.width_crowbar - deff_res.lock_box_size) / 2) &&
                            (x_ >= (deff_res.width_crowbar - deff_res.lock_box_size) / 2 - deff_res.box_size && x_ <= deff_res.width_crowbar - (deff_res.width_crowbar - deff_res.lock_box_size) / 2))
                        {
                            continue;
                        }

                        for (int y_1 = 1; y_1 <= deff_res.box_size; ++y_1)
                        {
                            for (int x_1 = 1; x_1 <= deff_res.box_size; ++x_1)
                            {
                                a = CaptureSc.info(x_ + x_1, y_ + y_1);

                                COLORREF color = RGB(a[0], a[1], a[2]);

                                if (GetRValue(color) >= GetRValue(min) && GetRValue(color) <= GetRValue(max) &&
                                    GetGValue(color) >= GetGValue(min) && GetGValue(color) <= GetGValue(max) &&
                                    GetBValue(color) >= GetBValue(min) && GetBValue(color) <= GetBValue(max))
                                {
                                    finded += 1;
                                }
                            }
                        }

                        if (finded > max_finded)
                        {
                            max_finded = finded;
                            findedVoidX = x_;
                            findedVoidY = y_;
                        }

                        finded = 0;
                    }
                }

                if (max_finded < deff_res.box_size * 2 || max_finded >(deff_res.box_size * deff_res.box_size) - deff_res.box_size * 2)
                {
                    continue;
                }

                if (last_findX - 10 <= deff_res.x_crowbar + findedVoidX && last_findX + 10 >= deff_res.x_crowbar + findedVoidX &&
                    last_findY - 10 <= deff_res.y_crowbar + findedVoidY && last_findY + 10 >= deff_res.y_crowbar + findedVoidY)
                {
                    continue;
                }

                //cout << "Find!!! " << deff_res.x_crowbar + findedVoidX
                //     << " | " << deff_res.y_crowbar + findedVoidY << endl;
                finded_b = true;
                last_findX = deff_res.x_crowbar + findedVoidX;
                last_findY = deff_res.y_crowbar + findedVoidY;
            }

            // Сравнивает кол-во пикселей по координатам, где нашло пустой кружок
            else if (finded_b == true)
            {
                CaptureSc.get_pixel(deff_res.x_crowbar + findedVoidX, deff_res.y_crowbar + findedVoidY, deff_res.box_size, deff_res.box_size);

                for (int y_1 = 1; y_1 <= deff_res.box_size; ++y_1)
                {
                    for (int x_1 = 1; x_1 <= deff_res.box_size; ++x_1)
                    {
                        a = CaptureSc.info(x_1, y_1);
                        COLORREF color = RGB(a[0], a[1], a[2]);

                        if (GetRValue(color) >= GetRValue(min) && GetRValue(color) <= GetRValue(max) &&
                            GetGValue(color) >= GetGValue(min) && GetGValue(color) <= GetGValue(max) &&
                            GetBValue(color) >= GetBValue(min) && GetBValue(color) <= GetBValue(max))
                        {
                            finded += 1;
                        }
                    }
                }
                
                // Кликает, когда точка в круге
                if (finded >= max_finded + 5)
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, findedVoidX, findedVoidY, 0, 0);
                    //cout << "Click! | " << finded << " | " << max_finded << endl;
 
                    finded_b = false;
                    max_finded = 0;
                }
                
                finded = 0;
            }

        }
        else
        {
            Sleep(5);
        }
        
    }
}
