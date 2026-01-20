#include "GameEngine.h"
#include "Constants.h"

namespace cnts = constants;  
namespace engine{
    
    /**
     * Testing sdl initilization with video
     * Change later
     */

    GameEngine::GameEngine(){
        SDL_Init(SDL_INIT_VIDEO);
        win = SDL_CreateWindow("Example gui", cnts::gScreenWidth, cnts::gScreenHeight, 0);
        ren = SDL_CreateRenderer(win, NULL);
        TTF_Init();
        font = TTF_OpenFont((cnts::gResPath + "fonts/ARIAL.TTF").c_str(), 24); 
    }

    GameEngine::~GameEngine(){
        TTF_CloseFont(font); 
        TTF_Quit();
        SDL_DestroyRenderer(ren); 
        SDL_DestroyWindow(win);
        SDL_Quit(); 
    }

    void GameEngine::add(CompPtr ptr){
        components.push_back(ptr);
    }

    void GameEngine::run(){
        bool running = true; 
        SDL_Event event; 

        while(running){                                         //Main game engine loop
		    while(SDL_PollEvent(&event)){                       //To check every event regardless of outer loop
			    switch(event.type){                             //Switch for adding other events later
                    case SDL_EVENT_QUIT: 
                        running = false; 
                        break; 
                } //switch
		    } //while event

            SDL_SetRenderDrawColor(ren, 50, 50, 50, 255);
		    SDL_RenderClear(ren);
            for(CompPtr comp : components) 
                comp->draw(); 
            
            SDL_RenderPresent(ren);
	    } //while running
    } //run

    GameEngine eng; 
} 