template <typename Transport>
requires concepts::InputTransport<Transport> class InputChannel
{
public:
    InputChannel(TransportArgs &&...transport_args)
    {
        _transport(std::forward<TransportArgs>(transportArgs)...) {}
        // . . .
    }

private:
    Transport _transport;
}