enum class Color
{
    red,
    blue,
    green
};
enum class TrafficLight
{
    green,
    yellow,
    red
};

int main()
{
    Color red = Color::red;
    TrafficLight traffic_red = TrafficLight::red;

    // These reds are not assignable to one another even though at its core they are both integers
    // red = traffic_red;
}