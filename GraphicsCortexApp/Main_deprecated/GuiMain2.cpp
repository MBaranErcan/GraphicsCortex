#include "GraphicsCortex.h"

int main() {
	Frame frame(1920, 1080, "Cortex GUI", 0, 0, true, true, true, Frame::CallbackLevel::LOW, false);
	Gui gui(frame);

	std::shared_ptr<Text> text = std::make_shared<Text>(Gui::font, "Haha");

	Style style1;
	style1.color = vec3(1, 1, 1);
	style1.border_color = vec3(0, 0, 0);
	style1.border_thickness = vec4(1, 1, 1, 1);

	Style style2;
	style2.color = vec3(1, 0, 0);
	style2.border_color = vec3(0, 0, 0);
	style2.border_thickness = vec4(1, 1, 1, 1);

	Style style3;
	style3.color = vec3(1, 1, 0);
	style3.border_color = vec3(0, 0, 0);
	style3.border_thickness = vec4(1, 1, 1, 1);

	Style style4;
	style4.color = vec3(1, 0, 1);
	style4.border_color = vec3(0, 0, 0);
	style4.border_thickness = vec4(1, 1, 1, 1);
	style4.on_hover.color = vec3(0, 0, 1);
	style4.on_hover.border_thickness = vec4(4, 4, 4, 4);
	style4.color_change = 0.3;
	style4.border_thickness_change = 0.3;
	style4.corner_rounding = vec4(20, 20, 20, 20);
	
	while (frame.is_running()) {
		double deltatime = frame.handle_window();
		frame.clear_window(1, 1, 1, 1);
		frame.display_performance(2000);

		gui.box("example_box", vec2(100, 100), vec2(100, 100), style1, U"Hello GUI");

		gui.override_style.padding = vec4(5, 5, 5, 5);
		gui.layout("example1", vec2(300, 100), vec2(0, 0), style1);
		gui.override_style.clear();
		gui.content("example2", vec2(200, 20), style2, U"Hello Layout");

		gui.override_style.color = vec3(0, 1, 1);
		gui.override_style.margin = vec4(5, 5, 5, 5);
		gui.override_style.on_hover.margin = vec4(5, 20, 5, 5);
		gui.override_style.margin_change = 0.6;
		gui.content("example3", vec2(200, 20), style2, U"Hello Layout");
		gui.override_style.clear();
		gui.content("example4", vec2(200, 40), style2, U"Hello Layout");
		gui.content("example5", vec2(200, 50), style2, U"Hello Layout");

		gui.override_style.padding = vec4(5, 5, 5, 5);
		gui.layout_content("example6", vec2(1300, 600), style1, Layout::Horizional);
		gui.override_style.clear();
		gui.content("example7", vec2(200, 30), style3, U"Hello linked lists");
		gui.content("example8", vec2(200, 30), style3, U"Hello linked lists");
		gui.content("example9", vec2(200, 30), style3, U"Hello linked lists");

		gui.override_style.padding = vec4(10, 10, 10, 10);
		gui.override_style.on_hover.margin = vec4(20, 20, 20, 20);
		gui.override_style.margin_change = 0.9;
		gui.override_style.margin_interpolation = Interpolation::polynomial(4);
		gui.override_style.on_hover.corner_rounding = vec4(20, 20, 20, 20);
		gui.override_style.corner_rounding_change = 0.9;
		gui.override_style.corner_rounding_interpolation = Interpolation::polynomial(4);
		gui.override_style.cursor_type = Frame::Hand;
		gui.layout_content("example10", vec2(0, 0), style1, Layout::Vertical);
		gui.override_style.color = vec3(0, 1, 0);
		gui.content("example11", vec2(200, 60), style4, U"Hello Recursion");
		gui.override_style.clear();
		gui.content("example12", vec2(200, 60), style4, U"Hello Recursion");
		gui.content("example13", vec2(200, 120), style4, U"Hello Recursion");
		
		gui.layout_content_end();

		gui.content("example14", vec2(200, 60), style3, U"Hello linked lists");

		gui.layout_content_end();

		gui.layout_end();

		gui.new_frame(deltatime);
	}
}