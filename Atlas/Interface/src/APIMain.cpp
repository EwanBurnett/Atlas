#ifdef _WIN32
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
#elif defined __linux__
#include <dlfcn.h>

int main(int argc, char** argv)
{
    /* on Linux, use "./myclass.so" */
    //void* handle = dlopen("myclass.so", RTLD_LAZY);

    //MyClass* (*create)();
    //void (*destroy)(MyClass*);

    //create = (MyClass * (*)())dlsym(handle, "create_object");
    //destroy = (void (*)(MyClass*))dlsym(handle, "destroy_object");

    //MyClass* myClass = (MyClass*)create();
    //myClass->DoSomething();
    //destroy(myClass);
}

#endif
