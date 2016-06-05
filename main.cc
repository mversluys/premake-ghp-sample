#define ASIO_STANDALONE
#define _WEBSOCKETPP_CPP11_STRICT_

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

typedef websocketpp::server<websocketpp::config::asio> WebSocketServer;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

using std::cout;
using std::endl;

class Server
{
public:
	Server();
	void Run();

private:

	void OnOpen(websocketpp::connection_hdl handle);
	void OnClose(websocketpp::connection_hdl handle);
	void OnMessageHTTP(websocketpp::connection_hdl handle);
	void OnMessageWebSocket(websocketpp::connection_hdl handle, WebSocketServer::message_ptr message);

	WebSocketServer m_server;			
};

Server::Server() 
{
	m_server.set_open_handler(bind(&Server::OnClose, this, _1));
	m_server.set_close_handler(bind(&Server::OnClose, this, _1));
	m_server.set_http_handler(bind(&Server::OnMessageHTTP, this, _1));
	m_server.set_message_handler(bind(&Server::OnMessageWebSocket, this, _1, _2));

	m_server.set_user_agent("Premake GHP Sample/0.1");

	m_server.init_asio();
	m_server.set_reuse_addr(true);
	m_server.listen(9000);
	m_server.start_accept();
}

void Server::Run()
{
	m_server.run();
}

void Server::OnOpen(websocketpp::connection_hdl handle)
{
	cout << "open" << endl;
}

void Server::OnClose(websocketpp::connection_hdl handle)
{
	cout << "closed" << endl;
}

void Server::OnMessageHTTP(websocketpp::connection_hdl handle)
{
	WebSocketServer::connection_ptr connection = m_server.get_con_from_hdl(handle);
	websocketpp::uri_ptr uri = connection->get_uri();
	auto request = connection->get_request();

	cout << "http: " << request.get_method() << " " << uri->str() << endl;

	connection->set_body(std::string("hello"));
	connection->set_status(websocketpp::http::status_code::ok);
}

void Server::OnMessageWebSocket(websocketpp::connection_hdl handle, WebSocketServer::message_ptr message)
{
	cout << "ws: " << message->get_payload() << endl;
}

int main(int argc, const char* argv[])
{
	Server server;
	server.Run();
	return 0;
}

