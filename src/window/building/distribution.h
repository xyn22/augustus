#ifndef WINDOW_BUILDING_DISTRIBUTION_H
#define WINDOW_BUILDING_DISTRIBUTION_H

#include "common.h"
#include "input/mouse.h"

void window_building_draw_dock(building_info_context *c);
void window_building_draw_dock_orders_foreground(building_info_context* c);
void window_building_draw_dock_orders(building_info_context* c);
void window_building_draw_dock_foreground(building_info_context* c);

int window_building_handle_mouse_dock(const mouse* m, building_info_context* c);
int window_building_handle_mouse_dock_orders(const mouse* m, building_info_context* c);

void window_building_draw_market(building_info_context *c);
void window_building_draw_market_foreground(building_info_context *c);
void window_building_draw_market_orders(building_info_context *c);
void window_building_draw_market_orders_foreground(building_info_context *c, int food_only, int limit_resource, int resource_id_1, int resource_id_2);

void window_building_handle_mouse_market(const mouse* m, building_info_context* c);
void window_building_handle_mouse_market_orders(const mouse* m, building_info_context* c);

void window_building_draw_mess_hall(building_info_context* c);

void window_building_draw_granary(building_info_context *c);
void window_building_draw_granary_foreground(building_info_context *c);
void window_building_draw_granary_orders(building_info_context *c);
void window_building_draw_granary_orders_foreground(building_info_context *c);

int window_building_handle_mouse_granary(const mouse *m, building_info_context *c);
int window_building_handle_mouse_granary_orders(const mouse *m, building_info_context *c);

void window_building_get_tooltip_granary_orders(int *group_id, int *text_id, int *translation);

void window_building_draw_warehouse(building_info_context *c);
void window_building_draw_warehouse_foreground(building_info_context *c);
void window_building_draw_warehouse_orders(building_info_context *c);
void window_building_draw_warehouse_orders_foreground(building_info_context *c);

int window_building_handle_mouse_warehouse(const mouse *m, building_info_context *c);
int window_building_handle_mouse_warehouse_orders(const mouse *m, building_info_context *c);

void window_building_granary_get_tooltip_distribution_permissions(int* translation);
void window_building_warehouse_get_tooltip_distribution_permissions(int* translation);
void window_building_get_tooltip_warehouse_orders(int *group_id, int *text_id, int *translation);

#endif // WINDOW_BUILDING_DISTRIBUTION_H
