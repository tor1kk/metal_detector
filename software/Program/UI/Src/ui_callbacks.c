/**
 * @file ui_callbacks.c
 * @brief User Interface callbacks source for MetalDetector project.
 * @version 1.4.1
 * @date 2024-07-30
 *
 * LVGL version: 9.1.0
 * Project name: MetalDetector
 */

#include "ui.h"
#include "metal_detecting.h"


/**
 * @brief Callback for when the phase arc changes.
 * @param e The event object
 */
void arc_phase_changed_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    char buf[8];

    lv_snprintf(buf, sizeof(buf), "%d", (int)lv_arc_get_value(obj));

    lv_label_set_text(ui_PhaseLabel, buf);
}

/**
 * @brief Callback for when the depth bar changes.
 * @param e The event object
 */
void depth_changed_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    char buf[8];

    lv_snprintf(buf, sizeof(buf), "%d", (int)lv_bar_get_value(obj));

    lv_label_set_text(ui_DepthLabel, buf);
}

/**
 * @brief Callback for when the ground balance changes.
 * @param e The event object
 */
void gnd_balance_changed_cb(lv_event_t * e)
{
    char buf[8];
    lv_obj_t * obj = lv_event_get_target(e);
    uint16_t gnd_balance = lv_slider_get_value(obj);

    lv_snprintf(buf, sizeof(buf), "%d", (uint32_t)gnd_balance);

    lv_label_set_text(ui_GndBalanceVal, buf);

    md_set_gndbalance(&md_handle, gnd_balance);
}

/**
 * @brief Callback for when the sensitivity changes.
 * @param e The event object
 */
void sens_changed_cb(lv_event_t * e)
{
    char buf[8];
    lv_obj_t * obj = lv_event_get_target(e);
    uint16_t sens = lv_slider_get_value(obj);

    lv_snprintf(buf, sizeof(buf), "%d", (uint32_t)sens);

    lv_label_set_text(ui_SenseVal, buf);

    md_set_sensitivity(&md_handle, sens);
}

/**
 * @brief Callback for when the ground balance button is pressed.
 * @param e The event object
 */
void gnd_balance_set_cb(lv_event_t * e)
{
    /* TODO */
}

/**
 * @brief Callback for when the chart domain dropdown changes.
 * @param e The event object
 */
void chart_domain_changed_cb(lv_event_t * e)
{
    lv_obj_t * dropdown = lv_event_get_target(e);
    char buf[64];

    lv_dropdown_get_selected_str(dropdown, buf, sizeof(buf));

    if (strcmp(buf, "Chart Time Domain") == 0)
    {
        lv_chart_hide_series(ui_Chart, ui_Chart_series_2, 0);
        lv_chart_set_point_count(ui_Chart, TIME_DOMAIN_CHART_LEN);
        lv_chart_set_range(ui_Chart, LV_CHART_AXIS_PRIMARY_Y, 0, TIME_DOMAIN_MAX_VALUE);
        ui_chart_domain = CHART_TIME_DOMAIN;
    }
    else if (strcmp(buf, "Chart Frequency Domain") == 0)
    {
        lv_chart_hide_series(ui_Chart, ui_Chart_series_2, 1);
        lv_chart_set_point_count(ui_Chart, FREQ_DOMAIN_CHART_LEN);
        lv_chart_set_range(ui_Chart, LV_CHART_AXIS_PRIMARY_Y, 0, FREQ_DOMAIN_MAX_VALUE);
        ui_chart_domain = CHART_FREQ_DOMAIN;
    }
}



