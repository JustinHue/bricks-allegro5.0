
#include <allegro5/allegro.h>

int main() 
{

	// set up application & allegro
	al_set_org_name("Justin Hellsten");
	al_set_app_name("Bricks");

	al_init();

	// create display
	//al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_set_new_display_refresh_rate(60);
	al_create_display(800, 600);

}

