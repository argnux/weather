# Weather monitoring application

## Assignment
Write a realization for weather conditions monitoring using OpenWeatherMap API and components from Boost library.

The program is divided into 3 modules:
- `network` - is responsible for connecting to the external server, sending a request, and receiving a response.
- `client` - is responsible for passing data to `network`, processing results from it, and printing results on a screen.
- `application` - is responsible for processing command-line arguments and passing them to `client`.

The program must be capable of:
- Showing help (as shown in `application.hpp`), if no arguments present or it was `-h` or `--help` argument;
- Reading city from the console;
- Reading token from console (If not present, check the file `token.txt` in the same directory as executable). Remember, token - is your secret information.
- Showing information about the weather in specified city. (as shown in `application.hpp`):
    - Name of the city
    - Temperature (degree Celsius)
    - Wind velocity (meters per second)
    - Wind direction (degrees)
- Connection to the server:
    - Reading host - `api.openweathermap.org` (must be set as default)
    - Reading port - `80` (must be set as default)
- Correct behavior when it can't connect to the server:
    - Prints `"Can't reach server"` when a connection could not be established
    - Prints `"Can't get weather in %city_name%"` when a city does not exist
    - Does not terminate with a non-zero error code in other cases

For header files, only appending is allowed.\
`main.cpp` is forbidden for modification.\
Must use Boost.Asio and Boost.Beast to work with the network, and Boost.Program to handle command-line arguments.\
Must use CMake to build the application. Name of the program must be `Weather`.

### Receiving a token
1. Open the following site: https://home.openweathermap.org/users/sign_up
2. Sing up there
3. In the purpose field select "Education/science"
4. Check your email, open letter, and press "Verify"
5. Your API will be here: https://home.openweathermap.org/api_keys
6. Read the API doc: https://openweathermap.org/current

## Maintainer

### Test cases
- [x] Shows help
- [x] Can read city from a console
- [x] Can read token from a console
- [x] Can read token from a file
- [x] Prints weather in existing city
- [x] Uses default address and port, can select other address and port
- [x] Prints correct message when a connection could not be established
- [x] Prints correct message when a city does not exist

### Code review
Technologies used:
- [x] CMake for building
- [x] boost::asio
- [x] boost::beast
- [x] boost::program

Style:
- [x] No raw pointers used and no potential memory leaks exist
- [x] Potential errors are wrapped in try-catch
- [x] Header guards are present
