
#include <stdio.h>
#include <allegro5/allegro.h>

int main() 
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	// set up system vars & allegro
	al_set_org_name("Justin Hellsten");
	al_set_app_name("Bricks");

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	// set up display
	al_set_new_display_refresh_rate(60);

	display = al_create_display(800, 600);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	// set up event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event queue!\n");
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	// clear screen to black
	al_clear_to_color(al_map_rgb(0,0,0));
 	al_flip_display();
 
  while(1) {
  	ALLEGRO_EVENT ev;
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.06);
 
    bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);
 
    if(get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
    	break;
    }
 
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
  }

  al_destroy_display(display);
  al_destroy_event_queue(event_queue);

}

