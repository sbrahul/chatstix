/* 
 * File:   CStixCallbackTemplate.h
 * Author: gnarayan
 *
 * Created on December 24, 2009, 11:58 AM
 *
 * This code is amongst the simplest implementations of C++ template based
 * callbacks. It is available at,
 * http://www.partow.net/programming/templatecallback/index.html#Download
 *
 * C++ template callbacks are difficult owing to specific class-linked
 * method signatures and over-the-top interface design considerations.
 *
 * Five separate overloaded classes are used to define callback templates,
 * 1. 4 parameters
 * 2. 3 parameters
 * 3. 2 parameters
 * 4. 1 parameter
 * 5. 0 parameters
 * 
 */

#ifndef _CSTIXCALLBACKTEMPLATE_H
#define	_CSTIXCALLBACKTEMPLATE_H

/*
 * Four parameter.
 */
template < class Class, typename ReturnType, typename Parameter1 = void,
                                             typename Parameter2 = void,
                                             typename Parameter3 = void,
                                             typename Parameter4 = void >
class CStixCallbackTemplate {

   public:

    typedef ReturnType (Class::*Method)(Parameter1, Parameter2, Parameter3, Parameter4);

    CStixCallbackTemplate(Class* _class_instance, Method _method)
    {
       class_instance = _class_instance;
       method         = _method;
    };

    ReturnType operator()(Parameter1 p1, Parameter2 p2, Parameter3 p3, Parameter4 p4)
    {
       return (class_instance->*method)(p1, p2, p3, p4);
    };

    ReturnType execute(Parameter1 p1, Parameter2 p2, Parameter3 p3, Parameter4 p4)
    {
       return operator()(p1, p2, p3, p4);
    };

    private:

      Class*  class_instance;
      Method  method;

};

/*
 * Three parameter
 */
template < class Class, typename ReturnType, typename Parameter1,
                                             typename Parameter2,
                                             typename Parameter3>
class CStixCallbackTemplate  < Class, ReturnType, Parameter1, Parameter2, Parameter3 >
{

   public:

    typedef ReturnType (Class::*Method)(Parameter1, Parameter2, Parameter3);

    CStixCallbackTemplate(Class* _class_instance, Method _method)
    {
       class_instance = _class_instance;
       method         = _method;
    };

    ReturnType operator()(Parameter1 p1, Parameter2 p2, Parameter3 p3)
    {
       return (class_instance->*method)(p1, p2, p3);
    };

    ReturnType execute(Parameter1 p1, Parameter2 p2, Parameter3 p3)
    {
       return operator()(p1, p2, p3);
    };

    private:

      Class*  class_instance;
      Method  method;

};

/*
 * Two parameter.
 */
template < class Class, typename ReturnType, typename Parameter1, typename Parameter2 >
class CStixCallbackTemplate < Class, ReturnType, Parameter1, Parameter2 >
{

   public:

    typedef ReturnType (Class::*Method)(Parameter1,Parameter2);

    CStixCallbackTemplate(Class* _class_instance, Method _method)
    {
       class_instance = _class_instance;
       method         = _method;
    };

    ReturnType operator()(Parameter1 p1, Parameter2 p2)
    {
       return (class_instance->*method)(p1, p2);
    };

    ReturnType execute(Parameter1 p1, Parameter2 p2)
    {
       return operator()(p1, p2);
    };

    private:

      Class*  class_instance;
      Method  method;

};

/*
 * Single parameter.
 */
template < class Class, typename ReturnType, typename Parameter>
class CStixCallbackTemplate < Class, ReturnType, Parameter >
{

   public:

    typedef ReturnType (Class::*Method)(Parameter);

    CStixCallbackTemplate(Class* _class_instance, Method _method)
    {
       class_instance = _class_instance;
       method         = _method;
    };

    ReturnType operator()(Parameter p1)
    {
       return (class_instance->*method)(p1);
    };

    ReturnType execute(Parameter p1)
    {
       return operator()(p1);
    };

    private:

      Class*  class_instance;
      Method  method;

};

/*
 * No parameter.
 */
template < class Class, typename ReturnType>
class CStixCallbackTemplate < Class, ReturnType >
{

   public:

    typedef ReturnType (Class::*Method)(void);

    CStixCallbackTemplate(Class* _class_instance, Method _method)
    {
       class_instance = _class_instance;
       method         = _method;
    };

    ReturnType operator()()
    {
       return (class_instance->*method)();
    };

    ReturnType execute()
    {
       return operator()();
    };

    private:

      Class*  class_instance;
      Method  method;

};

#endif	/* _CSTIXCALLBACKTEMPLATE_H */

