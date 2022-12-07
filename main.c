#include <stdio.h>
#include <SDL2/SDL.h>

const int WIDTH = 800;
const int HEIGHT = 600;

int main(int argc, char *argv[]){
    SDL_Init( SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow( "Hello SDL WORLD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (NULL == window){
        printf("could not create window: %s\n\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer( window, -1, 0);

    int red = 0;
    int green = 0;
    int blue = 0;

    SDL_SetRenderDrawColor( renderer, red, green, blue, 255);

    SDL_RenderClear( renderer);

    SDL_RenderPresent(renderer);

    SDL_Event event;
    while(1){
        if( SDL_PollEvent( &event)){
            if (SDL_QUIT == event.type){
                break;
            }

            if( SDL_MOUSEMOTION == event.type){
                int x,y;
                red = x*255/WIDTH;
                green = y*255/HEIGHT;
                SDL_GetMouseState(&x, &y);
                printf("\r%i        %i                ",x,y);
            }

            if(SDL_MOUSEBUTTONDOWN == event.type){
                if(SDL_BUTTON_LEFT == event.button.button){
                    printf("\rleft mouse button is clicked  ");
                }
                else if(SDL_BUTTON_RIGHT == event.button.button){
                    printf("\rright mouse button is clicked ");
                } 
                else if(SDL_BUTTON_MIDDLE == event.button.button){
                    printf("\rmiddle mouse button is clicked");
                }
            }

            if(SDL_MOUSEBUTTONUP == event.type){
                if(SDL_BUTTON_LEFT == event.button.button){
                    printf("\rleft mouse button is let go   ");
                }
                else if(SDL_BUTTON_RIGHT == event.button.button){
                    printf("\rright mouse button is let go  ");
                } 
                else if(SDL_BUTTON_MIDDLE == event.button.button){
                    printf("\rmiddle mouse button is let go ");
                }
            }

            if(SDL_MOUSEWHEEL == event.type){
                if(event.wheel.y > 0){
                    printf("\rscroll up                     ");
                }
                else if(event.wheel.y < 0){
                    printf("\rscroll down                   ");
                }

                // it is worth noting you can do with side
                // scroll with wheel.x

                blue = blue + event.wheel.y;
                if(blue>255){
                    blue = 255;
                }else if (blue < 0){
                    blue = 0;
                }
            }

            if(SDL_KEYDOWN == event.type){
                //printf("key is down\n");

                if(SDLK_a == event.key.keysym.sym){
                    printf("\rA is pressed, move left       ");
                }
                else if(SDLK_s == event.key.keysym.sym){
                    printf("\rS is pressed, move down       ");
                }
                else if(SDLK_d == event.key.keysym.sym){
                    printf("\rD is pressed, move right      ");
                }
                else if(SDLK_w == event.key.keysym.sym){
                    printf("\rW is pressed, move up         ");
                }
                else if(SDLK_f == event.key.keysym.sym){
                    printf("\r                                   ");
                    printf("\rrgb:\t%i  \t%i  \t%i\n",red,green,blue);
                    printf("Saved Color!");
                }
                else if(SDLK_ESCAPE){
                    printf("\r                              ");
                    break;
                }
            }
            else if (SDL_KEYUP == event.type){
                //printf("key is up\n");
                if(SDLK_a == event.key.keysym.sym){
                    printf("\rA is lifted, don't move left  ");
                }
                else if(SDLK_s == event.key.keysym.sym){
                    printf("\rS is lifted, don't move down  ");
                }
                else if(SDLK_d == event.key.keysym.sym){
                    printf("\rD is lifted, don't move right ");
                }
                else if(SDLK_w == event.key.keysym.sym){
                    printf("\rW is lifted, don't move up    ");
                }
            }
        }

            SDL_SetRenderDrawColor( renderer, red, green, blue, 255);
            SDL_RenderClear( renderer);
            SDL_RenderPresent( renderer);
            SDL_Delay(1000/60);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}