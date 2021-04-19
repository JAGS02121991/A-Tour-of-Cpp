template <typename T, int N>
class Buffer
{
    using value_type = T;

    size()
    {
        return N;
    }

    // ...
};

Buffer<int, 10> glob; // Will allocate 10 ints on STACK globally; not on HEAP

int main()
{

    {
        Buffer<char, 2048> buff; // Will allocate 2KB on STACK locally; not on HEAP
    }
}