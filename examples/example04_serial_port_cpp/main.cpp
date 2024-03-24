#include <iostream>
#include <boost/asio.hpp>

bool led0 = false;

// Function to read from the serial port
void readFromSerial(boost::asio::serial_port& serial) {
    boost::asio::streambuf buffer;
    boost::asio::read_until(serial, buffer, '\n');
    std::istream is(&buffer);
    std::string line;
    std::getline(is, line);
    std::cout << "Received: " << line << std::endl;
}

// Function to write to the serial port
void writeToSerial(boost::asio::serial_port& serial, const std::string& message) {
    boost::asio::write(serial, boost::asio::buffer(message + "\n"));
    std::cout << "Sent: " << message << std::endl;
}

int main(int argc, char *argv[]) {
    boost::asio::io_service io;
    boost::asio::serial_port serial(io);

    try {
        serial.open(argv[1]); // Adjust the serial port name as needed

        serial.set_option(boost::asio::serial_port_base::baud_rate(115200)); // Adjust baud rate as needed
        serial.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
        serial.set_option(boost::asio::serial_port_base::character_size(8));

        // Write to serial port
        std::string tx_data = "led0=" + std::to_string(led0);
        tx_data += "\r\n";
        writeToSerial(serial, tx_data);

        // Read from serial port
        readFromSerial(serial);
    } catch (boost::system::system_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    serial.close();
    return 0;
}
