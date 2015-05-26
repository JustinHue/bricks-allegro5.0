
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>																

const float FPS = 100;
const float UPS = 1;

int x = 0;

void __update__(); // update game per tick
void __render__(); // render game per tick

int main() 
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *fps_timer = NULL;
	ALLEGRO_TIMER *ups_timer = NULL;
	bool redraw = true;
	bool update = true;

	// set up system vars & allegro
	al_set_org_name("Justin Hellsten");
	al_set_app_name("Bricks");

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

  fps_timer = al_create_timer(1.0 / FPS);
	ups_timer = al_create_timer(1.0 / UPS);
  if(!fps_timer || !ups_timer) {
  	fprintf(stderr, "failed to create timers!\n");
    return -1;
  }

	// set up display
	al_set_new_display_refresh_rate(60);

	display = al_create_display(800, 600);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	// install primitives addon
	if (!al_init_primitives_addon()) {
		fprintf(stderr, "failed to initialize primitives addon!\n");
		return -1;
	}

	// set up event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event queue!\n");
		return -1;
	}

	// Register event sources to event queue
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(fps_timer));
	al_register_event_source(event_queue, al_get_timer_event_source(ups_timer));


	// clear screen to black
	al_clear_to_color(al_map_rgb(0,0,0));
 	al_flip_display();

 	al_start_timer(fps_timer);
	al_start_timer(ups_timer);

  while(1) {
  	ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
 
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			update = true;
		} else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
    	break;
    }
 
		if (al_is_event_queue_empty(event_queue)) {
			if (redraw) {
				redraw = false;
				__render__();
				al_flip_display();
				al_clear_to_color(al_map_rgb(0,0,0));
			}
			if (update) {
				update = false;
				__update__();
			}
		}

  }

	al_destroy_timer(fps_timer);
	al_destroy_timer(ups_timer);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
	
}

void __update__() {
	++x;
}

void __render__() {
	/* blue vertical line */
	al_draw_line(x, 1, 50, 100, al_map_rgb(0,0,255), 1);
	/* red horizontal line */
	al_draw_line(2, 1, 6, 100, al_map_rgb(255,0,0), 2);
	/* green filled rectangle */
	al_draw_filled_rectangle(3, 4, 5, 5, al_map_rgb(0,255,0));
}

