#include "third-party/include/serial/serial.h"
#include <iostream>
#include "thread"

int main()
{
    serial::Serial my_serial("/dev/ttyACM0", 9600, serial::Timeout::simpleTimeout(3000));

    if (my_serial.isOpen())
    {
        std::cout << "Port opened succesfully" << std::endl;
    }
    else
    {
        std::cout << "Port failed to open" << std::endl;
    }
    my_serial.flushOutput();

    std::string data = "";

    // SDL_Init(SDL_INIT_GAMECONTROLLER);

    // SDL_GameController *controller = SDL_GameControllerOpen(0);
    // SDL_Event ev;

    // for(int i = 0; i < SDL_NumJoysticks(); i++) {
    //     if(SDL_IsGameController(i)) {
    //         std::cout << i << std::endl;
    //         controller = SDL_GameControllerOpen(i);
    //         break;
    //     }
    // }

    // int pos = 90;

    bool isRunning = true;

    while(isRunning) {

        // while(SDL_PollEvent(&ev) != 0) {

            // if(ev.type = SDL_QUIT){
            //     isRunning = false;
            // } else if(ev.type == SDL_CONTROLLER_AXIS_LEFTY) {
            //     pos = ev.caxis.value / 32768 * 180;
            // }

            // std::cout << pos << std::endl;

            // data = std::to_string(pos) + "\n";

            data = std::cin.get();

            my_serial.write(data);

            my_serial.flushOutput();

        // }

    }

    // SDL_Quit();

    // SDL_GameControllerClose(controller);
}