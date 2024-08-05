/**
 * @file ui_callbacks.h
 * @brief User Interface callbacks header for MetalDetector project.
 * @version 1.4.1
 * @date 2024-07-30
 *
 * LVGL version: 9.1.0
 * Project name: MetalDetector
 */

#ifndef _UI_CALLBACKS_H
#define _UI_CALLBACKS_H

#include "lvgl.h"

/**
 * @brief Callback for when the phase arc changes.
 * @param e The event object
 */
void arc_phase_changed_cb(lv_event_t * e);

/**
 * @brief Callback for when the depth bar changes.
 * @param e The event object
 */
void depth_changed_cb(lv_event_t * e);

/**
 * @brief Callback for when the ground balance changes.
 * @param e The event object
 */
void gnd_balance_changed_cb(lv_event_t * e);

/**
 * @brief Callback for when the ground balance button is pressed.
 * @param e The event object
 */
void gnd_balance_set_cb(lv_event_t * e);

/**
 * @brief Callback for when the sensitivity changes.
 * @param e The event object
 */
void sens_changed_cb(lv_event_t * e);

/**
 * @brief Callback for when the chart domain dropdown changes.
 * @param e The event object
 */
void chart_domain_changed_cb(lv_event_t * e);


#endif // _UI_CALLBACKS_H
