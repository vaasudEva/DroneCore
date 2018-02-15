#include <future>
#include <grpc++/server.h>
#include <memory>

#include "dronecore.h"

namespace dronecore::backend {

class DroneCoreBackend
{
public:
    DroneCoreBackend() {}
    ~DroneCoreBackend() {}

    int run(const int mavlink_listen_port = 14540);

private:
    int connect_to_vehicle(int port);
    bool add_udp_connection(int port);
    void log_uuid_on_timeout();
    void wait_for_discovery();
    std::future<uint64_t> wrapped_register_on_discover();

    int run_server();
    void setup_port(grpc::ServerBuilder &builder);

    dronecore::DroneCore dc;
    std::unique_ptr<grpc::Server> server;
};

} // namespace dronecore::backend
