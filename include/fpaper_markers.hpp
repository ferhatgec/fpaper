// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef FPAPER_FPAPER_MARKERS_HPP
#define FPAPER_FPAPER_MARKERS_HPP

#include "defs/fpaper_defs.hpp"

enum FPaperMarkers : const uch {
    START_MARKER        = 0x02,
    START_MARKER_2      = 0x46,
    START_MARKER_3      = 0x50,
    START_MARKER_4      = 0x61,
    START_MARKER_5      = 0x67,
    START_MARKER_6      = 0x65,

    START_OF_TEXT       = 0x26,
    END_OF_TEXT         = 0x15,

    STYLE_MARKER        = 0x1A,
    LIGHT_SET           = 0x30,
    BOLD_SET            = 0x31,
    DIM_SET             = 0x32,
    ITALIC_SET          = 0x33,
    UNDERLINED_SET      = 0x34,
    BLINK_SET           = 0x35,
    RAPID_BLINK_SET     = 0x36,

    COLOR_RESET         = 0x72,

    // These styles must be rendered by renderer implementation
    ALIGN_LEFT_SET      = 0x7B,
    ALIGN_CENTER_SET    = 0x7C,
    ALIGN_RIGHT_SET     = 0x7D,
    ALIGN_RESET         = 0x7E
};

namespace marker {
    static bool is_start_marker(uch& ch) { return (ch == START_MARKER) ? true : false; }
    static bool is_start_marker_2(uch& ch) { return (ch == START_MARKER_2) ? true : false; }
    static bool is_start_marker_3(uch& ch) { return (ch == START_MARKER_3) ? true : false; }
    static bool is_start_marker_4(uch& ch) { return (ch == START_MARKER_4) ? true : false; }
    static bool is_start_marker_5(uch& ch) { return (ch == START_MARKER_5) ? true : false; }
    static bool is_start_marker_6(uch& ch) { return (ch == START_MARKER_6) ? true : false; }

    static bool is_start_of_text(uch& ch) { return (ch == START_OF_TEXT) ? true : false; }
    static bool is_end_of_text(uch& ch) { return (ch == END_OF_TEXT) ? true : false; }

    static bool is_style_marker(uch& ch) { return (ch == STYLE_MARKER) ? true : false; }
    static bool is_light_marker(uch& ch) { return (ch == LIGHT_SET) ? true : false; }
    static bool is_bold_marker(uch& ch) { return (ch == BOLD_SET) ? true : false; }
    static bool is_dim_marker(uch& ch) { return (ch == DIM_SET) ? true : false; }
    static bool is_italic_marker(uch& ch) { return (ch == ITALIC_SET) ? true : false; }
    static bool is_underlined_marker(uch& ch) { return (ch == UNDERLINED_SET) ? true : false; }
    static bool is_blink_marker(uch& ch) { return (ch == BLINK_SET) ? true : false; }
    static bool is_rapid_blink_marker(uch& ch) { return (ch == RAPID_BLINK_SET) ? true : false; }

    static bool is_left_align(uch& ch) { return (ch == ALIGN_LEFT_SET) ? true : false; }
    static bool is_center_align(uch& ch) { return (ch == ALIGN_CENTER_SET) ? true : false; }
    static bool is_right_align(uch& ch) { return (ch == ALIGN_RIGHT_SET) ? true : false; }
    static bool is_reset_align(uch& ch) { return (ch == ALIGN_RESET) ? true : false; }
}

#endif // FPAPER_FPAPER_MARKERS_HPP
