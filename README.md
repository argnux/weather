# Weather monitoring application

## Prepare to build
```
sudo apt update
sudo apt install libboost-system-dev libboost-filesystem-dev libboost-program-options-dev -y
git clone https://github.com/argnux/weather.git
```

## Build
```
cmake -B build
cmake --build ./build
```

### Receiving a token
1. Open the following site: https://home.openweathermap.org/users/sign_up
2. Sing up there
3. In the purpose field select "Education/science"
4. Check your email, open letter, and press "Verify"
5. Your API will be here: https://home.openweathermap.org/api_keys
6. Read the API doc: https://openweathermap.org/current
