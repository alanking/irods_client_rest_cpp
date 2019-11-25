/**
* iRODS REST API
* This is the iRODS REST API
*
* OpenAPI spec version: 1.0.0
* Contact: info@irods.org
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/

#include "AccessApi.h"

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

AccessApi::AccessApi(Pistache::Address addr)
    : httpEndpoint(std::make_shared<Pistache::Http::Endpoint>(addr))
{ };

void AccessApi::init(size_t thr = 2) {
    auto opts = Pistache::Http::Endpoint::options()
        .threads(thr);
    httpEndpoint->init(opts);
    setupRoutes();
}

void AccessApi::start() {
    httpEndpoint->setHandler(router.handler());
    httpEndpoint->serve();
}

void AccessApi::shutdown() {
    httpEndpoint->shutdown();
}

void AccessApi::setupRoutes() {
    using namespace Pistache::Rest;

    Routes::Post(router, base + "/access", Routes::bind(&AccessApi::access_handler, this));

    // Default handler, called when a route is not found
    router.addCustomHandler(Routes::bind(&AccessApi::access_api_default_handler, this));
}

void AccessApi::access_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {

    // Getting the query params
    auto path = request.query().get("path");

    try {
      this->access(request.headers(), request.body(), path, response);
    } catch (std::runtime_error & e) {
      //send a 400 error
      response.send(Pistache::Http::Code::Bad_Request, e.what());
      return;
    }

}

void AccessApi::access_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    response.send(Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

}
}
}
}

