# Weather monitoring application

## Prepare to build
```
FIXME write the preparing
```

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
