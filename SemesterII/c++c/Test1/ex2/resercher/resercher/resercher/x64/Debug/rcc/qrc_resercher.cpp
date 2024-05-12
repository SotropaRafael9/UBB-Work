/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.5.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_resercher)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_resercher)()
{
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resercher)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resercher)()
{
    return 1;
}

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_resercher)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resercher)(); }
   } dummy;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#endif
