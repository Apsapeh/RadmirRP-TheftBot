#pragma once
#include "json.hpp"
using json = nlohmann::json;

struct default_res
{
	std::string name_trans;
	int x_trans;
	int y_trans;
	int width_trans;
	int height_trans;

	std::string name_crowbar;
	int x_crowbar;
	int y_crowbar;
	int width_crowbar;
	int height_crowbar;
	int box_size;
	int lock_box_size;
};

struct set_set
{
	bool show_donut;
	int crowbar_sleep;
	
	int min_r;
	int min_g;
	int min_b;
	
	int max_r;
	int max_g;
	int max_b;
};

struct custom_res_trans
{
	std::string name_trans;
	int x_trans;
	int y_trans;
	int width_trans;
	int height_trans;
};

struct custom_res_crow
{
	std::string name_crowbar;
	int x_crowbar;
	int y_crowbar;
	int width_crowbar;
	int height_crowbar;
	int box_size;
	int lock_box_size;
};

void t_c_func();
void transponder_function();
void crowbar_function();

int* setting_count(json a);
