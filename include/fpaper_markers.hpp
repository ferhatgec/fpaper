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
    BOLD_SET            = 0x31
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
}

#endif // FPAPER_FPAPER_MARKERS_HPP
