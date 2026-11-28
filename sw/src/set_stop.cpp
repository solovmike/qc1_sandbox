#include <unistd.h>
#include <iostream>
#include <moteus.h>
#include <pi3hat_moteus_transport.h>

int main(int argc, char** argv) {
	using namespace mjbots;

	pi3hat::Pi3HatMoteusFactory::Register();

	moteus::Controller::Options options1;
	moteus::Controller::Options options2;
	moteus::Controller::Options options3;

	options1.id = 1;
	options2.id = 2;
	options3.id = 3;


	moteus::Controller controller1(options1);
	moteus::Controller controller2(options2);
	moteus::Controller controller3(options3);

	controller1.SetStop();
	controller2.SetStop();
	controller3.SetStop();

#if 0
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

