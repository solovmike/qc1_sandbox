#include <unistd.h>
#include <iostream>
#include <moteus.h>
#include <pi3hat_moteus_transport.h>

int main(int argc, char** argv) {
	using namespace mjbots;

	pi3hat::Pi3HatMoteusFactory::Register();

	moteus::Controller::Options options;
	
	options.id = 1;

	moteus::Controller controller(options);

	controller.SetStop();

#if 1
	while (true) {
		moteus::PositionMode::Command cmd;
		
		cmd.position = std::numeric_limits<double>::quiet_NaN();
		cmd.velocity = 0.0;

	const auto maybe_result = controller.SetPosition(cmd);
	if (maybe_result) {
		const auto r = maybe_result->values;
		::printf("%3d p/v/t=(%7.3f,%7.3f,%7.3f)  v/t/f=(%5.1f,%5.1f,%3d)   \r",
		     static_cast<int>(r.mode),
		     r.position,
		     r.velocity,
		     r.torque,
		     r.voltage,
		     r.temperature,
		     r.fault);
		::fflush(stdout);
	}

    	::usleep(20000);
	}
#endif
}

