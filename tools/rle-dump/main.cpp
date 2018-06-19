extern "C" {
#include "keepkey/board/canvas.h"
#include "keepkey/board/draw.h"
#include "keepkey/board/variant.h"
}

#include <iostream>
#include <iomanip>

static const uint8_t confirm_icon_1_data[240] = {
    0x08, 0x00, 0xfc, 0x02, 0x11, 0x1e, 0x29, 0x02, 0x2f, 0xfc, 0x29, 0x1e, 0x11, 0x02, 0x0b, 0x00, 0xfe, 0x0d, 0x22, 0x08, 0x33, 0xfe, 0x22, 0x0d, 0x09, 0x00, 0xfe, 0x11, 0x2b, 0x0a, 0x33, 0xfe, 0x2b, 0x11, 0x07, 0x00, 0xfe, 0x0d, 0x2b, 0x05, 0x33, 0x02, 0x31, 0x05, 0x33, 0xfe, 0x2b, 0x0d, 0x05, 0x00, 0xfe, 0x02, 0x22, 0x06, 0x33, 0x02, 0x15, 0x06, 0x33, 0xfe, 0x22, 0x02, 0x04, 0x00, 0xff, 0x11, 0x06, 0x33, 0xff, 0x2b, 0x02, 0x01, 0xff, 0x2b, 0x06, 0x33, 0xff, 0x11, 0x04, 0x00, 0xff, 0x1e, 0x06, 0x33, 0xff, 0x0d, 0x02, 0x00, 0xff, 0x0d, 0x06, 0x33, 0xff, 0x1e, 0x04, 0x00, 0xff, 0x29, 0x05, 0x33, 0xff, 0x1f, 0x04, 0x00, 0xff, 0x1f, 0x05, 0x33, 0xff, 0x29, 0x04, 0x00, 0xff, 0x2f, 0x04, 0x33, 0xfe, 0x2f, 0x02, 0x04, 0x00, 0xfe, 0x02, 0x2f, 0x04, 0x33, 0xff, 0x2f, 0x04, 0x00, 0xff, 0x2f, 0x04, 0x33, 0xff, 0x11, 0x06, 0x00, 0xff, 0x15, 0x04, 0x33, 0xff, 0x2f, 0x04, 0x00, 0xff, 0x29, 0x03, 0x33, 0xff, 0x26, 0x08, 0x00, 0xff, 0x26, 0x03, 0x33, 0xff, 0x29, 0x04, 0x00, 0xff, 0x1e, 0x03, 0x33, 0xff, 0x11, 0x08, 0x07, 0xff, 0x15, 0x03, 0x33, 0xff, 0x1e, 0x04, 0x00, 0xff, 0x11, 0x10, 0x33, 0xff, 0x11, 0x04, 0x00, 0xfe, 0x02, 0x22, 0x0e, 0x33, 0xfe, 0x22, 0x02, 0x05, 0x00, 0xfe, 0x0d, 0x2b, 0x0c, 0x33, 0xfe, 0x2b, 0x0d, 0x07, 0x00, 0xfe, 0x11, 0x2b, 0x0a, 0x33, 0xfe, 0x2b, 0x11, 0x09, 0x00, 0xfe, 0x0d, 0x22, 0x08, 0x33, 0xfe, 0x22, 0x0d, 0x0b, 0x00, 0xfc, 0x02, 0x11, 0x1e, 0x29, 0x02, 0x2f, 0xfc, 0x29, 0x1e, 0x11, 0x02, 0x04, 0x00
};

static const VariantImage confirm_icon_1_image = {
  .w = 22,
  .h = 18,
  .length = sizeof(confirm_icon_1_data),
  .data = &confirm_icon_1_data[0]
};

static const AnimationFrame confirm_icon_1_frame = {
    .x = 233,
    .y = 4,
    .duration = 1,
    .color = 100,
    .image = &confirm_icon_1_image
};

void to_ppm(Canvas *canvas) {
    std::cout << "P3\n"
              << canvas->width << " " << canvas->height << "\n"
              << "255\n";

    for (uint16_t y = 0; y < canvas->height; y++) {
        for (uint16_t x = 0; x < canvas->width; x++) {
            int color = canvas->buffer[y * canvas->width + x];
            std::cout << std::setw(3) << color << " " << color << " " << color;
            if (x + 1 != canvas->width)
                std::cout << "    ";
            else
                std::cout << "\n";
        }
    }
}

int main(int argc, char *argv[]) {
    Canvas canvas;
    canvas.height = 64;
    canvas.width = 255;
    canvas.buffer = new uint8_t[64 * 255];

    memset(canvas.buffer, 0, 64 * 255);

    if (!canvas.buffer)
        return 1;

    if (draw_bitmap_mono_rle(&canvas, &confirm_icon_1_frame, false)) {
        to_ppm(&canvas);
        return 0;
    }

    return 2;
}
