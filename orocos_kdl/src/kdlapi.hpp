#ifndef kdlapi_hpp
#define kdlapi_hpp

#if defined(_MSC_VER)
    #define KDL_DLLIMPORT           __declspec(dllimport)
    #define KDL_DLLEXPORT           __declspec(dllexport)
#elif defined(__GNUC__)
    #define KDL_DLLIMPORT           __attribute__((visibility("default")))
    #define KDL_DLLEXPORT           __attribute__((visibility("default")))
#endif

#if defined(ENABLE_KDL_DLLIMPORT)
    #define KDL_DLLAPI              KDL_DLLIMPORT
#elif defined(ENABLE_KDL_DLLEXPORT)
    #define KDL_DLLAPI              KDL_DLLEXPORT
#else
    #define KDL_DLLAPI 
#endif

#endif
