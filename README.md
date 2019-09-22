# REST API Server for iRODS REST API

## Overview
This API Server was generated by the [swagger-codegen](https://github.com/swagger-api/swagger-codegen) project.
It uses the [Pistache](https://github.com/oktal/pistache) Framework.


## Files organization
The Pistache C++ REST server generator creates three folders:
- `api`: This folder contains the handlers for each method specified in the swagger definition. Every handler extracts
the path and body parameters (if any) from the requests and tries to parse and possibly validate them.
Once this step is completed, the main API class calls the corresponding abstract method that should be implemented
by the developer (a basic implementation is provided under the `impl` folder)
- `impl`: As written above, the implementation folder contains, for each API, the corresponding implementation class,
which extends the main API class and implements the abstract methods.
Every method receives the path and body parameters as constant reference variables and a reference to the response
object, that should be filled with the right response and sent at the end of the method with the command:
response.send(returnCode, responseBody, [mimeType])
- `model`: This folder contains the corresponding class for every object schema found in the swagger specification.

The main folder contains also a file with a main that can be used to start the server.
Of course, is you should customize this file based on your needs

## Installation
First of all, you need to download and install the libraries listed [here](#libraries-required).

Once the libraries are installed, in order to compile and run the server please follow the steps below:
```bash
mkdir build
cd build
cmake ..
make
```

Once compiled run the server:

```bash
cd build
./server
```

## Libraries required
- [pistache](http://pistache.io/quickstart)
- [JSON for Modern C++](https://github.com/nlohmann/json/#integration): Please download the `json.hpp` file and
put it under the model folder

## Namespaces
io::swagger::server::api

io::swagger::server::model
