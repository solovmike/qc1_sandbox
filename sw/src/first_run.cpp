#include <unistd.h>
#include <iostream>
#include <moteus.h>
#include <pi3hat_moteus_transport.h>

int main() {
	using namespace mjbots;

	pi3hat::Pi3HatMoteusFactory::Register();

	auto transport = moteus::Controller::MakeSingletonTransport({});

	size_t servo_count = 3;

	std::vector<std::shared_ptr<moteus::Controller>> controllers;

	for(size_t i = 1; i <= servo_count; ++i) {
		moteus::Controller::Options options;
		options.id = i;
		
		controllers.push_back(std::make_shared<moteus::Controller>(options));
	}

	for(const auto &c : controllers) c->SetStop();

	std::vector<moteus::CanFdFrame> commands_to_send;
	std::vector<moteus::CanFdFrame> replies_to_receive;

	moteus::PositionMode::Command cmd;

#if 1
	while (true) {
		
		commands_to_send.clear();
		replies_to_receive.clear();

		cmd.position = std::numeric_limits<double>::quiet_NaN();
		cmd.velocity = 0.0;

		for(const auto &c : controllers)
			commands_to_send.push_back(c->MakePosition(cmd));

		transport->BlockingCycle(
				commands_to_send.data(),
				commands_to_send.size(),
				&replies_to_receive);

		const auto maybe_result = false; 

#if 0
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
#endif

		::usleep(20000);
	}
#endif
}

