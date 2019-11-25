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
/*
 * AccessApi.h
 *
 * 
 */

#ifndef AccessApi_H_
#define AccessApi_H_


#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>
#include "ModelBase.h"

#include <string>

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

class  AccessApi {
public:
    AccessApi(Pistache::Address addr);
    virtual ~AccessApi() {};
    void init(size_t thr);
    void start();
    void shutdown();

    const std::string base = "/irods-rest/1.0.0";

private:
    void setupRoutes();

    void access_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void access_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);

    std::shared_ptr<Pistache::Http::Endpoint> httpEndpoint;
    Pistache::Rest::Router router;


    /// <summary>
    /// obtain an access token and url for a given object
    /// </summary>
    /// <remarks>
    /// obtain an access token and url for a given object 
    /// </remarks>
    /// <param name="path">irods absolute logical path of the object</param>
    virtual void access(const Pistache::Http::Header::Collection& headers, const std::string body, const Pistache::Optional<std::string> &path, Pistache::Http::ResponseWriter &response) = 0;

};

}
}
}
}

#endif /* AccessApi_H_ */

