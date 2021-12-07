// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef FPAPER_FPAPER_EXTRACT_HPP
#define FPAPER_FPAPER_EXTRACT_HPP

#include "fpaper.hpp"
#include "fpaper_markers.hpp"

class FPaper_Extract {
    FPaper clone;

    bool is_start_marker        = false,
         is_start_marker_2      = false,
         is_start_marker_3      = false,
         is_start_marker_4      = false,
         is_start_marker_5      = false,
         is_start_marker_6      = false,

         is_start_of_text       = false,
         is_end_of_text         = false,

         is_style_marker        = false,

         is_left_align          = false,
         is_center_align        = false,
         is_right_align         = false,
         is_reset_align         = false;
public:
         std::string extracted_text;
public:
    FPaper_Extract(FPaper& x) noexcept {
        this->clone = x;
    }
    ~FPaper_Extract() = default;

    void DetectStyle(uch ch) noexcept {
        // not platform specific.
        switch(ch) {
            case LIGHT_SET: {
                this->extracted_text.append("\x1b[0m"); break;
            }

            case BOLD_SET: {
                this->extracted_text.append("\x1b[1m"); break;
            }

            case DIM_SET: {
                this->extracted_text.append("\x1b[2m"); break;
            }

            case ITALIC_SET: {
                this->extracted_text.append("\x1b[3m"); break;
            }

            case UNDERLINED_SET: {
                this->extracted_text.append("\x1b[4m"); break;
            }

            case BLINK_SET: {
                this->extracted_text.append("\x1b[5m"); break;
            }

            case RAPID_BLINK_SET: {
                #if defined(_WIN64) || defined(_WIN32)
                    this->extracted_text.append("\x1b[6m"); break;
                #endif // defined(_WIN64) || defined(_WIN32)
            }

            case ALIGN_LEFT_SET: {
                this->is_right_align         =
                        this->is_center_align=
                        this->is_reset_align = false;

                this->is_left_align = true; break;
            }

            case ALIGN_CENTER_SET: {
                this->is_right_align         =
                        this->is_left_align  =
                        this->is_reset_align = false;

                this->is_center_align = true; break;
            }

            case ALIGN_RIGHT_SET: {
                this->is_center_align        =
                        this->is_left_align  =
                        this->is_reset_align = false;

                this->is_right_align = true; break;
            }

            case ALIGN_RESET: {
                this->is_center_align        =
                        this->is_left_align  =
                        this->is_reset_align =
                        this->is_right_align = false; break;
            }

            case COLOR_RESET: {
                this->extracted_text.append("\x1b[0m"); break;
            }

            default: {
                if((ch >= 40 && ch <= 49) || (ch >= 100 && ch <= 109)) {
                    this->extracted_text.append("\x1b[" + std::to_string(ch - 10) + "m");
                } break;
            }
        }
    }

    void Detect(uch ch) noexcept {
        if(this->is_style_marker) {
            this->DetectStyle(ch);
            this->is_style_marker = false; return;
        }

        if(!this->is_start_marker) {
            this->is_start_marker = marker::is_start_marker(ch);
        }
        else if(!this->is_start_marker_2) {
            this->is_start_marker_2 = marker::is_start_marker_2(ch);
        }
        else if(!this->is_start_marker_3) {
            this->is_start_marker_3 = marker::is_start_marker_3(ch);
        }
        else if(!this->is_start_marker_4) {
            this->is_start_marker_4 = marker::is_start_marker_4(ch);
        }
        else if(!this->is_start_marker_5) {
            this->is_start_marker_5 = marker::is_start_marker_5(ch);
        }
        else if(!this->is_start_marker_6) {
            this->is_start_marker_6 = marker::is_start_marker_6(ch);
        }
        else if(!this->is_start_of_text) {
            this->is_start_of_text  = marker::is_start_of_text(ch);
        }
        else if(this->is_start_of_text) {
            if(marker::is_style_marker(ch)) {
                this->is_style_marker = true; return;
            }

            if(marker::is_end_of_text(ch)) {
                this->is_end_of_text = true; return;
            }

            extracted_text.push_back(ch);
        }
    }

    void Extract() noexcept {
        for(auto& ch : this->clone.raw) {
            if(this->is_end_of_text) { break; }

            this->Detect(ch);
        }

        std::cout << this->extracted_text << '\n';
    }
};

#endif // FPAPER_FPAPER_EXTRACT_HPP
