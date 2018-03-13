//
//  GCTFoundationClangConstants.h
//  GCTFoundationDemo
//
//  Created by Later on 2018/2/20.
//  Copyright © 2018年 GEEKCODE.In. All rights reserved.
//

#ifndef GCTFoundationClangConstants_h
#define GCTFoundationClangConstants_h

#pragma mark - Clang

#define GCTArgumentToString(macro) #macro
#define GCTClangWarningConcat(warning_name) ArgumentToString(clang diagnostic ignored warning_name)

// 参数可直接传入 clang 的 warning 名，warning 列表参考：http://fuckingclangwarnings.com/
#define GCTIgnoreClangWarningBegin(warningName) _Pragma("clang diagnostic push") _Pragma(ClangWarningConcat(#warningName))
#define GCTIgnoreClangWarningEnd _Pragma("clang diagnostic pop")

//-WCFString-literal input conversion stopped due to an input byte that does not belong to the input codeset UTF-8
#define GCT_IGNORE_WCFSTRING_LITERAL_WARNING_BEGIN GCTIgnoreClangWarningBegin(-WCFString-literal)
#define GCT_IGNORE_WCFSTRING_LITERAL_WARNING_END GCTIgnoreClangWarningEnd

//-WNSObject-attribute __attribute ((NSObject)) may be put on a typedef only, attribute is ignored
#define GCT_IGNORE_WNSOBJECT_ATTRIBUTE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-WNSObject-attribute)
#define GCT_IGNORE_WNSOBJECT_ATTRIBUTE_WARNING_END GCTIgnoreClangWarningEnd

//-Wabstract-vbase-init    initializer for virtual base class %0 of abstract class %1 will never be used
#define GCT_IGNORE_WABSTRACT_VBASE_INIT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wabstract-vbase-init)
#define GCT_IGNORE_WABSTRACT_VBASE_INIT_WARNING_END GCTIgnoreClangWarningEnd

//-Waddress-of-array-temporary    pointer is initialized by a temporary array, which will be destroyed at the end of the full-expression
#define GCT_IGNORE_WADDRESS_OF_ARRAY_TEMPORARY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Waddress-of-array-temporary)
#define GCT_IGNORE_WADDRESS_OF_ARRAY_TEMPORARY_WARNING_END GCTIgnoreClangWarningEnd

//-Warc-maybe-repeated-use-of-weak    "weak %select{variable|property|implicit property|instance variable}0 %1 may be accessed multiple times in this %select{function|method|block|lambda}2 and may be unpredictably set to nil assign to a strong variable to keep the object alive
#define GCT_IGNORE_MAYBE_REPEATED_USE_OF_WEAK_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Warc-maybe-repeated-use-of-weak)
#define GCT_IGNORE_MAYBE_REPEATED_USE_OF_WEAK_WARNING_END GCTIgnoreClangWarningEnd

//-Warc-non-pod-memaccess    %select{destination for|source of}0 this %1 call is a pointer to ownership-qualified type %2
#define GCT_IGNORE_NON_POD_MEMACCESS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Warc-non-pod-memacces)
#define GCT_IGNORE_NON_POD_MEMACCESS_WARNING_END GCTIgnoreClangWarningEnd

//-Warc-performSelector-leaks    performSelector may cause a leak because its selector is unknown
#define GCT_IGNORE_PERFORM_SEL_LEAKS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Warc-performSelector-leaks)
#define GCT_IGNORE_PERFORM_SEL_LEAKS_WARNING_END GCTIgnoreClangWarningEnd


//-Warc-repeated-use-of-weak    weak %select{variable|property|implicit property|instance variable}0 %1 is accessed multiple times in this %select{function|method|block|lambda}2 but may be unpredictably set to nil assign to a strong variable to keep the object alive
#define GCT_IGNORE_REPEATED_USE_OF_WEAK_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Warc-repeated-use-of-weak)
#define GCT_IGNORE_REPEATED_USE_OF_WEAK_WARNING_END GCTIgnoreClangWarningEnd

//-Warc-retain-cycles    capturing %0 strongly in this block is likely to lead to a retain cycle
#define GCT_IGNORE_RETAIN_CYCLES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Warc-retain-cycles)
#define GCT_IGNORE_RETAIN_CYCLES_WARNING_END GCTIgnoreClangWarningEnd

//-Warc-unsafe-retained-assign    assigning retained object to unsafe property object will be released after assignment
//-Warc-unsafe-retained-assign    assigning %select{array literal|dictionary literal|numeric literal|boxed expression|should not happen|block literal}0 to a weak %select{property|variable}1 object will be released after assignment
//-Warc-unsafe-retained-assign    assigning retained object to %select{weak|unsafe_unretained}0 %select{property|variable}1 object will be released after assignment

#define GCT_IGNORE_UNSAFE_RETAINED_ASSIGN_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Warc-unsafe-retained-assign)
#define GCT_IGNORE_UNSAFE_RETAINED_ASSIGN_WARNING_END GCTIgnoreClangWarningEnd

//-Warray-bounds    array index %0 is past the end of the array (which contains %1 element%s2)
//-Warray-bounds    array index %0 is before the beginning of the array
//-Warray-bounds    'static' has no effect on zero-length arrays
//-Warray-bounds    array argument is too small contains %0 elements, callee requires at least %1
#define GCT_IGNORE_WARRAY_BOUNDS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Warray-bounds)
#define GCT_IGNORE_WARRAY_BOUNDS_WARNING_END GCTIgnoreClangWarningEnd

//-Warray-bounds-pointer-arithmetic    the pointer incremented by %0 refers past the end of the array (that contains %1 element%s2)
//-Warray-bounds-pointer-arithmetic    the pointer decremented by %0 refers before the beginning of the array
#define GCT_IGNORE_WARRAY_BOUNDS_POINTER_ARITHMETIC_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Warray-bounds-pointer-arithmetic)
#define GCT_IGNORE_WARRAY_BOUNDS_POINTER_ARITHMETIC_WARNING_END GCTIgnoreClangWarningEnd

//-Wassign-enum    integer constant not in range of enumerated type %0
#define GCT_IGNORE_WASSIGN_ENUM_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wassign-enum)
#define GCT_IGNORE_WASSIGN_ENUM_WARNING_END GCTIgnoreClangWarningEnd

//-Watomic-property-with-user-defined-accessor    writable atomic property %0 cannot pair a synthesized %select{getter|setter}1 with a user defined %select{getter|setter}2
#define GCT_IGNORE_WATOMIC_PROPERTY_WITH_USER_DEFINED_ACCESSOR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Watomic-property-with-user-defined-accessor)
#define GCT_IGNORE_WATOMIC_PROPERTY_WITH_USER_DEFINED_ACCESSOR_WARNING_END GCTIgnoreClangWarningEnd

//-Wattributes    unknown attribute %0 ignored
#define GCT_IGNORE_WATTRIBUTES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wattributes)
#define GCT_IGNORE_WATTRIBUTES_WARNING_END GCTIgnoreClangWarningEnd

//-Wauto-var-id    'auto' deduced as 'id' in declaration of %0
#define GCT_IGNORE_WAUTO_VAR_ID_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wauto-var-id)
#define GCT_IGNORE_WAUTO_VAR_ID_WARNING_END GCTIgnoreClangWarningEnd

//-Wavailability    unknown platform %0 in availability macro
//-Wavailability    overriding method %select{introduced after|deprecated before|obsoleted before}0 overridden method on %1 (%2 vs. %3)
//-Wavailability    availability does not match previous declaration
//-Wavailability    overriding method cannot be unavailable on %0 when its overridden method is available
//-Wavailability    feature cannot be %select{introduced|deprecated|obsoleted}0 in %1 version %2 before it was %select{introduced|deprecated|obsoleted}3 in version %4 attribute ignored
#define GCT_IGNORE_WAVAILABILITY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wavailability)
#define GCT_IGNORE_WAVAILABILITY_WARNING_END GCTIgnoreClangWarningEnd

//-Wbad-function-cast    cast from function call of type %0 to non-matching type %1
#define GCT_IGNORE_WBAD_FUNCTION_CAST_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wbad-function-cast)
#define GCT_IGNORE_WBAD_FUNCTION_CAST_WARNING_END GCTIgnoreClangWarningEnd

//-Wbitfield-constant-conversion    implicit truncation from %2 to bitfield changes value from %0 to %1
#define GCT_IGNORE_WBITFIELD_CONSTANT_CONVERSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wbitfield-constant-conversion)
#define GCT_IGNORE_WBITFIELD_CONSTANT_CONVERSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wbitwise-op-parentheses    '&' within '|'
#define GCT_IGNORE_WBITWISE_OP_PARENTHESES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wbitwise-op-parentheses)
#define GCT_IGNORE_WBITWISE_OP_PARENTHESES_WARNING_END GCTIgnoreClangWarningEnd

//-Wbool-conversion    "initialization of pointer of type %0 to null from a constant boolean " "expression
#define GCT_IGNORE_WBOOL_CONVERSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wbool-conversion)
#define GCT_IGNORE_WBOOL_CONVERSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wbridge-cast    %0 cannot bridge to %1
//-Wbridge-cast    %0 bridges to %1, not %2
#define GCT_IGNORE_WBRIDGE_CAST_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wbridge-cast)
#define GCT_IGNORE_WBRIDGE_CAST_WARNING_END GCTIgnoreClangWarningEnd

//-Wbuiltin-requires-header    declaration of built-in function '%0' requires inclusion of the header stdio.h
//-Wbuiltin-requires-header    declaration of built-in function '%0' requires inclusion of the header setjmp.h
//-Wbuiltin-requires-header    declaration of built-in function '%0' requires inclusion of the header ucontext.h
#define GCT_IGNORE_WBUILTIN_REQUIRES_HEADER_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wbuiltin-requires-header)
#define GCT_IGNORE_WBUILTIN_REQUIRES_HEADER_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++-compat    %select{|empty }0%select{struct|union}1 has size 0 in C, %select{size 1|non-zero size}2 in C++
#define GCT_IGNORE_WC_COPMAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++-compat)
#define GCT_IGNORE_WC_COPMAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++11-compat    explicit instantiation cannot be 'inline'
//-Wc++11-compat    explicit instantiation of %0 must occur at global scope
//-Wc++11-compat    explicit instantiation of %0 not in a namespace enclosing %1
//-Wc++11-compat    explicit instantiation of %q0 must occur in namespace %1
#define GCT_IGNORE_WC11_COPMAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++11-compat)
#define GCT_IGNORE_WC11_COPMAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++11-narrowing    constant expression evaluates to %0 which cannot be narrowed to type %1 in C++11
//-Wc++11-narrowing    type %0 cannot be narrowed to %1 in initializer list in C++11
//-Wc++11-narrowing    non-constant-expression cannot be narrowed from type %0 to %1 in initializer list in C++11
#define GCT_IGNORE_WC11_NARROWING_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++11-narrowing)
#define GCT_IGNORE_WC11_NARROWING_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++98-c++11-compat    type definition in a constexpr %select{function|constructor}0 is incompatible with C++ standards before C++1y
//-Wc++98-c++11-compat    use of this statement in a constexpr %select{function|constructor}0 is incompatible with C++ standards before C++1y
//-Wc++98-c++11-compat    init-captures.def warn_cxx11_compat_init_capture : Warning "initialized lambda captures are incompatible with C++ standards " "before C++1y
//-Wc++98-c++11-compat    variable declaration in a constexpr %select{function|constructor}0 is incompatible with C++ standards before C++1y
//-Wc++98-c++11-compat    constexpr function with no return statements is incompatible with C++ standards before C++1y
//-Wc++98-c++11-compat    multiple return statements in constexpr function is incompatible with C++ standards before C++1y
//-Wc++98-c++11-compat    variable templates are incompatible with C++ standards before C++1y
#define GCT_IGNORE_WC98_C11_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++98-c++11-compat)
#define GCT_IGNORE_WC98_C11_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++98-compat    substitution failure due to access control is incompatible with C++98
//-Wc++98-compat    %select{anonymous struct|union}0 member %1 with a non-trivial %select{constructor|copy constructor|move constructor|copy assignment operator|move assignment operator|destructor}2 is incompatible with C++98
//-Wc++98-compat    enumeration type in nested name specifier is incompatible with C++98
//-Wc++98-compat    static data member %0 in union is incompatible with C++98
//-Wc++98-compat    default template arguments for a function template are incompatible with C++98
//-Wc++98-compat    scalar initialized from empty initializer list is incompatible with C++98
//-Wc++98-compat    befriending %1 without '%select{struct|interface|union|class|enum}0' keyword is incompatible with C++98
//-Wc++98-compat    use of null pointer as non-type template argument is incompatible with C++98
//-Wc++98-compat    friend declaration naming a member of the declaring class is incompatible with C++98
//-Wc++98-compat    non-class friend type %0 is incompatible with C++98
//-Wc++98-compat    befriending enumeration type %0 is incompatible with C++98
//-Wc++98-compat    use of non-static data member %0 in an unevaluated context is incompatible with C++98
//-Wc++98-compat    friend function %0 would be implicitly redefined in C++98
//-Wc++98-compat    %select{class template|class template partial|variable template|variable template partial|function template|member function|static data member|member class|member enumeration}0 specialization of %1 outside namespace %2 is incompatible with C++98
//-Wc++98-compat    reference initialized from initializer list is incompatible with C++98
//-Wc++98-compat    redundant parentheses surrounding address non-type template argument are incompatible with C++98
//-Wc++98-compat    initialization of initializer_list object is incompatible with C++98
//-Wc++98-compat    use of 'template' keyword outside of a template is incompatible with C++98
//-Wc++98-compat    non-type template argument referring to %select{function|object}0 %1 with internal linkage is incompatible with C++98
//-Wc++98-compat    use of 'typename' outside of a template is incompatible with C++98
//-Wc++98-compat    passing object of trivial but non-POD type %0 through variadic %select{function|block|method|constructor}1 is incompatible with C++98
//-Wc++98-compat    goto would jump into protected scope in C++98
//-Wc++98-compat    constructor call from initializer list is incompatible with C++98
//-Wc++98-compat    'auto' type specifier is incompatible with C++98
//-Wc++98-compat    delegating constructors are incompatible with C++98
//-Wc++98-compat    'constexpr' specifier is incompatible with C++98
//-Wc++98-compat    inheriting constructors are incompatible with C++98
//-Wc++98-compat    explicit conversion functions are incompatible with C++98
//-Wc++98-compat    switch case would be in a protected scope in C++98
//-Wc++98-compat    '%0' type specifier is incompatible with C++98
//-Wc++98-compat    indirect goto might cross protected scopes in C++98
#define GCT_IGNORE_WC98_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++98-compat)
#define GCT_IGNORE_WC98_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++98-compat-pedantic    cast between pointer-to-function and pointer-to-object is incompatible with C++98
//-Wc++98-compat-pedantic    implicit conversion from array size expression of type %0 to %select{integral|enumeration}1 type %2 is incompatible with C++98
#define GCT_IGNORE_WC98_COMPAT_PEDANTIC_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++98-compat-pedantic)
#define GCT_IGNORE_WC98_COMPAT_PEDANTIC_WARNING_END GCTIgnoreClangWarningEnd

//-Wcast-align    cast from %0 to %1 increases required alignment from %2 to %3
#define GCT_IGNORE_WCAST_ALOGN_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wcast-align)
#define GCT_IGNORE_WCAST_ALOGN_WARNING_END GCTIgnoreClangWarningEnd

//-Wcast-of-sel-type    cast of type %0 to %1 is deprecated use sel_getName instead
#define GCT_IGNORE_WCAST_OF_SEL_TYPE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wcast-of-sel-type)
#define GCT_IGNORE_WCAST_OF_SEL_TYPE_WARNING_END GCTIgnoreClangWarningEnd

//-Wchar-subscripts    array subscript is of type 'char'
#define GCT_IGNORE_WCHAR_SUBSCRIPTS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wchar-subscripts)
#define GCT_IGNORE_WCHAR_SUBSCRIPTS_WARNING_END GCTIgnoreClangWarningEnd

//-Wconditional-uninitialized    variable %0 may be uninitialized when %select{used here|captured by block}1
#define GCT_IGNORE_WCONDITIONAL_UNINITIALIZED_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wconditional-uninitialized)
#define GCT_IGNORE_WCONDITIONAL_UNINITIALIZED_WARNING_END GCTIgnoreClangWarningEnd

//-Wconstant-logical-operand    use of logical '%0' with constant operand
#define GCT_IGNORE_WCONSTANT_LOGICAL_OPERAND_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wconstant-logical-operand)
#define GCT_IGNORE_WCONSTANT_LOGICAL_OPERAND_WARNING_END GCTIgnoreClangWarningEnd

//-Wconstexpr-not-const    'constexpr' non-static member function will not be implicitly 'const' in C++1y add 'const' to avoid a change in behavior
#define GCT_IGNORE_WCONSTANT_NOT_CONST_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wconstexpr-not-const)
#define GCT_IGNORE_WCONSTANT_NOT_CONST_WARNING_END GCTIgnoreClangWarningEnd

//-Wconsumed    state of variable '%0' must match at the entry and exit of loop
//-Wconsumed    parameter '%0' not in expected state when the function returns: expected '%1', observed '%2'
//-Wconsumed    argument not in expected state expected '%0', observed '%1'
//-Wconsumed    invalid invocation of method '%0' on a temporary object while it is in the '%1' state
//-Wconsumed    return state set for an unconsumable type '%0'
//-Wconsumed    consumed analysis attribute is attached to member of class '%0' which isn't marked as consumable
//-Wconsumed    invalid invocation of method '%0' on object '%1' while it is in the '%2' state
//-Wconsumed    return value not in expected state expected '%0', observed '%1'
#define GCT_IGNORE_WCONSUMED_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wconsumed)
#define GCT_IGNORE_WCONSUMED_WARNING_END GCTIgnoreClangWarningEnd

//-Wconversion    implicit conversion discards imaginary component: %0 to %1
//-Wconversion    non-type template argument with value '%0' converted to '%1' for unsigned template parameter of type %2
//-Wconversion    implicit conversion loses floating-point precision: %0 to %1
//-Wconversion    implicit conversion loses integer precision: %0 to %1
//-Wconversion    non-type template argument value '%0' truncated to '%1' for template parameter of type %2
//-Wconversion    implicit conversion turns vector to scalar: %0 to %1
//-Wconversion    implicit conversion turns floating-point number into integer: %0 to %1
#define GCT_IGNORE_WCONVERSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wconversion)
#define GCT_IGNORE_WCONVERSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wcovered-switch-default    default label in switch which covers all enumeration values
#define GCT_IGNORE_WCOVERED_SWITCH_DEFAULT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wcovered-switch-default)
#define GCT_IGNORE_WCOVERED_SWITCH_DEFAULT_WARNING_END GCTIgnoreClangWarningEnd

//-Wcustom-atomic-properties    atomic by default property %0 has a user defined %select{getter|setter}1 (property should be marked 'atomic' if this is intended)
#define GCT_IGNORE_WCUSTOM_ATOMIC_PROPERTIES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wcustom-atomic-properties)
#define GCT_IGNORE_WCUSTOM_ATOMIC_PROPERTIES_WARNING_END GCTIgnoreClangWarningEnd

//-Wdangling-field    initializing pointer member %0 with the stack address of parameter %1
//-Wdangling-field    binding reference %select{|subobject of }1member %0 to a temporary value
//-Wdangling-field    binding reference member %0 to stack allocated parameter %1
#define GCT_IGNORE_WDANGLING_FIELD_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdangling-field)
#define GCT_IGNORE_WDANGLING_FIELD_WARNING_END GCTIgnoreClangWarningEnd

//-Wdangling-initializer-list    array backing the initializer list will be destroyed at the end of %select{the full-expression|the constructor}0
#define GCT_IGNORE_WDANGLING_INITIALIZER_LIST_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdangling-initializer-list)
#define GCT_IGNORE_WDANGLING_INITIALIZER_LIST_WARNING_END GCTIgnoreClangWarningEnd

//-Wdelete-incomplete    deleting pointer to incomplete type %0 may cause undefined behavior
#define GCT_IGNORE_WDELETE_INCOMPLETE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdelete-incomplete)
#define GCT_IGNORE_WDELETE_INCOMPLETE_WARNING_END GCTIgnoreClangWarningEnd

//-Wdelete-non-virtual-dtor    delete called on %0 that is abstract but has non-virtual destructor
//-Wdelete-non-virtual-dtor    delete called on %0 that has virtual functions but non-virtual destructor
#define GCT_IGNORE_WDELETE_NON_VIRTUAL_DTOR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdelete-non-virtual-dtor)
#define GCT_IGNORE_WDELETE_NON_VIRTUAL_DTOR_WARNING_END GCTIgnoreClangWarningEnd

//-Wdeprecated    access declarations are deprecated use using declarations instead
//-Wdeprecated    definition of implicit copy %select{constructor|assignment operator}1 for %0 is deprecated because it has a user-declared %select{copy %select{assignment operator|constructor}1|destructor}2
//-Wdeprecated    dynamic exception specifications are deprecated
#define GCT_IGNORE_WDEPRECATED_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdeprecated)
#define GCT_IGNORE_WDEPRECATED_WARNING_END GCTIgnoreClangWarningEnd

//-Wdeprecated-increment-bool    incrementing expression of type bool is deprecated
#define GCT_IGNORE_WDEPRECATED_INCREMENT_BOOL_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdeprecated-increment-bool)
#define GCT_IGNORE_WDEPRECATED_INCREMENT_BOOL_WARNING_END GCTIgnoreClangWarningEnd

//-Wdeprecated-objc-isa-usage    assignment to Objective-C's isa is deprecated in favor of object_setClass()
//-Wdeprecated-objc-isa-usage    direct access to Objective-C's isa is deprecated in favor of object_getClass()
#define GCT_IGNORE_WDEPRECATED_OBJC_ISA_USAGE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdeprecated-objc-isa-usage)
#define GCT_IGNORE_WDEPRECATED_OBJC_ISA_USAGE_WARNING_END GCTIgnoreClangWarningEnd

//-Wdeprecated-objc-pointer-introspection    bitmasking for introspection of Objective-C object pointers is strongly discouraged
#define GCT_IGNORE_WDEPRECATED_OBJC_POINTER_INTROSPECTION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdeprecated-objc-pointer-introspection)
#define GCT_IGNORE_WDEPRECATED_OBJC_POINTER_INTROSPECTION_WARNING_END GCTIgnoreClangWarningEnd

//-Wdeprecated-objc-pointer-introspection-performSelector    warn_objc_pointer_masking.Text
#define GCT_IGNORE_WDEPRECATED_OBJC_POINTER_INTROSPECTION_PERFORMSELECTOR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdeprecated-objc-pointer-introspection-performSelector)
#define GCT_IGNORE_WDEPRECATED_OBJC_POINTER_INTROSPECTION_PERFORMSELECTOR_WARNING_END GCTIgnoreClangWarningEnd

//-Wdeprecated-writable-strings    dummy warning to enable -fconst-strings
#define GCT_IGNORE_WDEPRECATED_WRITABLE_STRINGS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdeprecated-writable-strings)
#define GCT_IGNORE_WDEPRECATED_WRITABLE_STRINGS_WARNING_END GCTIgnoreClangWarningEnd

//-Wdirect-ivar-access    instance variable %0 is being directly accessed
#define GCT_IGNORE_WDIRECT_IVAR_ACCESS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdirect-ivar-access)
#define GCT_IGNORE_WDIRECT_IVAR_ACCESS_WARNING_END GCTIgnoreClangWarningEnd

//-Wdistributed-object-modifiers    conflicting distributed object modifiers on return type in implementation of %0
//-Wdistributed-object-modifiers    conflicting distributed object modifiers on parameter type in implementation of %0
#define GCT_IGNORE_WDISTRIBUTED_OBJECT_MODIFIERS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdistributed-object-modifiers)
#define GCT_IGNORE_WDISTRIBUTED_OBJECT_MODIFIERS_WARNING_END GCTIgnoreClangWarningEnd

//-Wdivision-by-zero    division by zero is undefined
//-Wdivision-by-zero    remainder by zero is undefined
#define GCT_IGNORE_WDIVISION_BY_ZERO_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdivision-by-zero)
#define GCT_IGNORE_WDIVISION_BY_ZERO_WARNING_END GCTIgnoreClangWarningEnd

//-Wdocumentation    parameter '%0' not found in the function declaration
//-Wdocumentation    not a Doxygen trailing comment
#define GCT_IGNORE_WDOCUMENTATION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdocumentation)
#define GCT_IGNORE_WDOCUMENTATION_WARNING_END GCTIgnoreClangWarningEnd

//-Wduplicate-enum    element %0 has been implicitly assigned %1 which another element has been assigned
#define GCT_IGNORE_WDUPLICATE_ENUM_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wduplicate-enum)
#define GCT_IGNORE_WDUPLICATE_ENUM_WARNING_END GCTIgnoreClangWarningEnd

//-Wduplicate-method-match    multiple declarations of method %0 found and ignored
#define GCT_IGNORE_WDUPLICATE_METHOD_MATCH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wduplicate-method-match)
#define GCT_IGNORE_WDUPLICATE_METHOD_MATCH_WARNING_END GCTIgnoreClangWarningEnd

//-Wdynamic-class-memaccess    %select{destination for|source of|first operand of|second operand of}0 this %1 call is a pointer to dynamic class %2 vtable pointer will be %select{overwritten|copied|moved|compared}3
#define GCT_IGNORE_WDYNAMIC_CLASS_MEMACCESS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdynamic-class-memaccess)
#define GCT_IGNORE_WDYNAMIC_CLASS_MEMACCESS_WARNING_END GCTIgnoreClangWarningEnd

//-Wempty-body    switch statement has empty body
//-Wempty-body    for loop has empty body
//-Wempty-body    if statement has empty body
//-Wempty-body    range-based for loop has empty body
//-Wempty-body    while loop has empty body
#define GCT_IGNORE_WEMPTY_BODY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wempty-body)
#define GCT_IGNORE_WEMPTY_BODY_WARNING_END GCTIgnoreClangWarningEnd

//-Wenum-compare    comparison of two values with different enumeration types%diff{ ($ and $)|}0,1
#define GCT_IGNORE_WENUM_COMPARE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wenum-compare)
#define GCT_IGNORE_WENUM_COMPARE_WARNING_END GCTIgnoreClangWarningEnd

//-Wenum-conversion    implicit conversion from enumeration type %0 to different enumeration type %1
#define GCT_IGNORE_WENUM_CONVERSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wenum-conversion)
#define GCT_IGNORE_WENUM_CONVERSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wexit-time-destructors    declaration requires an exit-time destructor
#define GCT_IGNORE_WEXIT_TIME_DESTRUCTORS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wexit-time-destructors)
#define GCT_IGNORE_WEXIT_TIME_DESTRUCTORS_WARNING_END GCTIgnoreClangWarningEnd

//-Wexplicit-ownership-type    method parameter of type %0 with no explicit ownership
#define GCT_IGNORE_WEXPLICIT_OWNERSHIP_TYPE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wexplicit-ownership-type)
#define GCT_IGNORE_WEXPLICIT_OWNERSHIP_TYPE_WARNING_END GCTIgnoreClangWarningEnd

//-Wextern-c-compat    %select{|empty }0%select{struct|union}1 has size 0 in C, %select{size 1|non-zero size}2 in C++
#define GCT_IGNORE_WEXTERN_C_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wextern-c-compat)
#define GCT_IGNORE_WEXTERN_C_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wextern-initializer    'extern' variable has an initializer
#define GCT_IGNORE_WEXTERN_INITIALIZER_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wextern-initializer)
#define GCT_IGNORE_WEXTERN_INITIALIZER_WARNING_END GCTIgnoreClangWarningEnd

//-Wfloat-equal    comparing floating point with == or != is unsafe
#define GCT_IGNORE_WFLOAT_EQUAL_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wfloat-equal)
#define GCT_IGNORE_WFLOAT_EQUAL_WARNING_END GCTIgnoreClangWarningEnd

//-Wformat    "data argument position '%0' exceeds the number of data arguments (%1)
//-Wformat    position arguments in format strings start counting at 1 (not 0)
//-Wformat    invalid position specified for %select{field width|field precision}0
//-Wformat    cannot mix positional and non-positional arguments in format string
//-Wformat    values of type '%0' should not be used as format arguments add an explicit cast to %1 instead
//-Wformat    format specifies type %0 but the argument has type %1
//-Wformat    zero field width in scanf format string is unused
//-Wformat    no closing ']' for '%%[' in scanf format string
//-Wformat    format string should not be a wide string
//-Wformat    format string contains '\\0' within the string body
//-Wformat    '%select{*|.*}0' specified field %select{width|precision}0 is missing a matching 'int' argument
//-Wformat    field %select{width|precision}0 should have type %1, but argument has type %2
//-Wformat    %select{field width|precision}0 used with '%1' conversion specifier, resulting in undefined behavior
//-Wformat    format string missing
//-Wformat    incomplete format specifier
//-Wformat    flag '%0' results in undefined behavior with '%1' conversion specifier
//-Wformat    flag '%0' is ignored when flag '%1' is present
//-Wformat    more '%%' conversions than data arguments
//-Wformat    length modifier '%0' results in undefined behavior or no effect with '%1' conversion specifier
#define GCT_IGNORE_WFORMAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wformat)
#define GCT_IGNORE_WFORMAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wformat-extra-args    data argument not used by format string
#define GCT_IGNORE_WFORMAT_EXTRA_ARGS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wformat-extra-args)
#define GCT_IGNORE_WFORMAT_EXTRA_ARGS_WARNING_END GCTIgnoreClangWarningEnd

//-Wformat-invalid-specifier    invalid conversion specifier '%0'
#define GCT_IGNORE_WFORMAT_INVALID_SPECIFIER_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wformat-invalid-specifier)
#define GCT_IGNORE_WFORMAT_INVALID_SPECIFIER_WARNING_END GCTIgnoreClangWarningEnd

//-Wformat-nonliteral    format string is not a string literal
#define GCT_IGNORE_WFORMAT_NONLITERAL_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wformat-nonliteral)
#define GCT_IGNORE_WFORMAT_NONLITERAL_WARNING_END GCTIgnoreClangWarningEnd

//-Wformat-security    format string is not a string literal (potentially insecure)
#define GCT_IGNORE_WFORMAT_SECURITY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wformat-security)
#define GCT_IGNORE_WFORMAT_SECURITY_WARNING_END GCTIgnoreClangWarningEnd

//-Wformat-zero-length    format string is empty
#define GCT_IGNORE_WFORMAT_ZERO_LENGTH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wformat-zero-length)
#define GCT_IGNORE_WFORMAT_ZERO_LENGTH_WARNING_END GCTIgnoreClangWarningEnd

//-Wgcc-compat    GCC does not allow the 'cleanup' attribute argument to be anything other than a simple identifier
#define GCT_IGNORE_WGCC_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wgcc-compat)
#define GCT_IGNORE_WGCC_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wglobal-constructors    declaration requires a global constructor
//-Wglobal-constructors    declaration requires a global destructor
#define GCT_IGNORE_WGLOBAL_CONSTRUCTORS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wglobal-constructors)
#define GCT_IGNORE_WGLOBAL_CONSTRUCTORS_WARNING_END GCTIgnoreClangWarningEnd

//-Wgnu-conditional-omitted-operand    use of GNU ?: conditional expression extension, omitting middle operand
#define GCT_IGNORE_WGNU_CONDITIONAL_OMITTED_OPERAND_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wgnu-conditional-omitted-operand)
#define GCT_IGNORE_WGNU_CONDITIONAL_OMITTED_OPERAND_WARNING_END GCTIgnoreClangWarningEnd

//-Wheader-hygiene    using namespace directive in global context in header
#define GCT_IGNORE_WHEADER_HYGIENE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wheader-hygiene)
#define GCT_IGNORE_WHEADER_HYGIENE_WARNING_END GCTIgnoreClangWarningEnd

//-Widiomatic-parentheses    using the result of an assignment as a condition without parentheses
#define GCT_IGNORE_WIDIOMATIC_PARENTHESES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Widiomatic-parentheses)
#define GCT_IGNORE_WIDIOMATIC_PARENTHESES_WARNING_END GCTIgnoreClangWarningEnd

//-Wignored-attributes    'malloc' attribute only applies to functions returning a pointer type
//-Wignored-attributes    %0 attribute only applies to %select{functions|unions|variables and functions|functions and methods|parameters|functions, methods and blocks|functions, methods, and classes|functions, methods, and parameters|classes|variables|methods|variables, functions and labels|fields and global variables|structs|variables, functions and tag types|thread-local variables|variables and fields|variables, data members and tag types|types and namespaces|Objective-C interfaces}1
//-Wignored-attributes    '%0' attribute cannot be specified on a definition
//-Wignored-attributes    __weak attribute cannot be specified on an automatic variable when ARC is not enabled
//-Wignored-attributes    Objective-C GC does not allow weak variables on the stack
//-Wignored-attributes    __weak attribute cannot be specified on a field declaration
//-Wignored-attributes    attribute %0 cannot be applied to %select{functions|Objective-C method}1 without return value
//-Wignored-attributes    attribute declaration must precede definition
//-Wignored-attributes    attribute %0 is ignored, place it after \"%select{class|struct|union|interface|enum}1\" to apply attribute to type declaration
//-Wignored-attributes    __declspec attribute %0 is not supported
//-Wignored-attributes    attribute %0 ignored, because it cannot be applied to a type
//-Wignored-attributes    attribute %0 after definition is ignored
//-Wignored-attributes    %0 attribute ignored
//-Wignored-attributes    'sentinel' attribute only supported for variadic %select{functions|blocks}0
//-Wignored-attributes    'sentinel' attribute requires named arguments
//-Wignored-attributes    '%0' only applies to %select{function|pointer|Objective-C object or block pointer}1 types type here is %2
//-Wignored-attributes    'nonnull' attribute applied to function with no pointer arguments
//-Wignored-attributes    %0 attribute can only be applied to instance variables or properties
//-Wignored-attributes    ibaction attribute can only be applied to Objective-C instance methods
//-Wignored-attributes    %0 calling convention ignored on variadic function
//-Wignored-attributes    %0 only applies to variables with static storage duration and functions
//-Wignored-attributes    %0 attribute argument not supported: %1
//-Wignored-attributes    #pramga ms_struct can not be used with dynamic classes or structures
//-Wignored-attributes    transparent union definition must contain at least one field transparent_union attribute ignored
//-Wignored-attributes    first field of a transparent union cannot have %select{floating point|vector}0 type %1 transparent_union attribute ignored
//-Wignored-attributes    'gnu_inline' attribute requires function to be marked 'inline', attribute ignored
//-Wignored-attributes    calling convention %0 ignored for this target
//-Wignored-attributes    transparent_union attribute can only be applied to a union definition attribute ignored
//-Wignored-attributes    %select{alignment|size}0 of field %1 (%2 bits) does not match the %select{alignment|size}0 of the first field in transparent union transparent_union attribute ignored
//-Wignored-attributes    attribute %0 is already applied
//-Wignored-attributes    %0 attribute ignored for field of type %1
//-Wignored-attributes    %0 attribute ignored when parsing type
//-Wignored-attributes    %0 attribute only applies to %select{functions|methods|properties}1 that return %select{an Objective-C object|a pointer|a non-retainable pointer}2
//-Wignored-attributes    %0 attribute only applies to %select{Objective-C object|pointer}1 parameters
//-Wignored-attributes    attribute %0 is already applied with different parameters
//-Wignored-attributes    unknown visibility %0
#define GCT_IGNORE_WIGNORED_ATTRIBUTES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wignored-attributes)
#define GCT_IGNORE_WIGNORED_ATTRIBUTES_WARNING_END GCTIgnoreClangWarningEnd

//-Wignored-qualifiers    "'%0' type qualifier%s1 on return type %plural{1:has|:have}1 no effect
//-Wignored-qualifiers    ARC %select{unused|__unsafe_unretained|__strong|__weak|__autoreleasing}0 lifetime qualifier on return type is ignored
#define GCT_IGNORE_WIGNORED_QUALIFIERS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wignored-qualifiers)
#define GCT_IGNORE_WIGNORED_QUALIFIERS_WARNING_END GCTIgnoreClangWarningEnd

//-Wimplicit-atomic-properties    property is assumed atomic by default
//-Wimplicit-atomic-properties    property is assumed atomic when auto-synthesizing the property
#define GCT_IGNORE_WIMPLICIT_ATOMIC_PROPERTIES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wimplicit-atomic-properties)
#define GCT_IGNORE_WIMPLICIT_ATOMIC_PROPERTIES_WARNING_END GCTIgnoreClangWarningEnd

//-Wimplicit-fallthrough    fallthrough annotation in unreachable code
//-Wimplicit-fallthrough    unannotated fall-through between switch labels
//-Wimplicit-fallthrough    fallthrough annotation does not directly precede switch label
#define GCT_IGNORE_WIMPLICIT_FALLTHROUGH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wimplicit-fallthrough)
#define GCT_IGNORE_WIMPLICIT_FALLTHROUGH_WARNING_END GCTIgnoreClangWarningEnd

//-Wimplicit-function-declaration    implicit declaration of function %0
//-Wimplicit-function-declaration    use of unknown builtin %0
#define GCT_IGNORE_WIMPLICIT_FUNCTION_DECLARATION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wimplicit-function-declaration)
#define GCT_IGNORE_WIMPLICIT_FUNCTION_DECLARATION_WARNING_END GCTIgnoreClangWarningEnd

//-Wimplicit-retain-self    "block implicitly retains 'self' explicitly mention 'self' to indicate this is intended behavior
#define GCT_IGNORE_WIMPLICIT_RETAIN_SELF_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wimplicit-retain-self)
#define GCT_IGNORE_WIMPLICIT_RETAIN_SELF_WARNING_END GCTIgnoreClangWarningEnd

//-Wincompatible-library-redeclaration    incompatible redeclaration of library function %0
#define GCT_IGNORE_WIMPLICIT_LIBRARY_REDECLARATION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wincompatible-library-redeclaration)
#define GCT_IGNORE_WIMPLICIT_LIBRARY_REDECLARATION_WARNING_END GCTIgnoreClangWarningEnd

//-Wincomplete-implementation    method definition for %0 not found
#define GCT_IGNORE_WINCOMPLETE_IMPLEMENTATION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wincomplete-implementation)
#define GCT_IGNORE_WINCOMPLETE_IMPLEMENTATION_WARNING_END GCTIgnoreClangWarningEnd

//-Winherited-variadic-ctor    inheriting constructor does not inherit ellipsis
#define GCT_IGNORE_WINHERITED_VARIADIC_CTOR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Winherited-variadic-ctor)
#define GCT_IGNORE_WINHERITED_VARIADIC_CTOR_WARNING_END GCTIgnoreClangWarningEnd

//-Winitializer-overrides    subobject initialization overrides initialization of other fields within its enclosing subobject
//-Winitializer-overrides    initializer overrides prior initialization of this subobject
#define GCT_IGNORE_WINITIALIZER_OVERRIDES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Winitializer-overrides)
#define GCT_IGNORE_WINITIALIZER_OVERRIDES_WARNING_END GCTIgnoreClangWarningEnd

//-Wint-to-pointer-cast    cast to %1 from smaller integer type %0
#define GCT_IGNORE_WINT_TO_POINTER_CAST_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wint-to-pointer-cast)
#define GCT_IGNORE_WINT_TO_POINTER_CAST_WARNING_END GCTIgnoreClangWarningEnd

//-Wint-to-void-pointer-cast    cast to %1 from smaller integer type %0
#define GCT_IGNORE_WINT_TO_VOID_POINTER_CAST_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wint-to-void-pointer-cast)
#define GCT_IGNORE_WINT_TO_VOID_POINTER_CAST_WARNING_END GCTIgnoreClangWarningEnd

//-Winvalid-iboutlet    IBOutletCollection properties should be copy/strong and not assign
//-Winvalid-iboutlet    %select{instance variable|property}2 with %0 attribute must be an object type (invalid %1)
#define GCT_IGNORE_WINVALID_IBOUTLET_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Winvalid-iboutlet)
#define GCT_IGNORE_WINVALID_IBOUTLET_WARNING_END GCTIgnoreClangWarningEnd

//-Winvalid-noreturn    function %0 declared 'noreturn' should not return
//-Winvalid-noreturn    function declared 'noreturn' should not return
#define GCT_IGNORE_WINVALID_NORETURN_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Winvalid-noreturn)
#define GCT_IGNORE_WINVALID_NORETURN_WARNING_END GCTIgnoreClangWarningEnd

//-Wlarge-by-value-copy    return value of %0 is a large (%1 bytes) pass-by-value object pass it by reference instead ?
//-Wlarge-by-value-copy    %0 is a large (%1 bytes) pass-by-value argument pass it by reference instead ?
#define GCT_IGNORE_WLARGE_BY_VALUE_COPY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wlarge-by-value-copy)
#define GCT_IGNORE_WLARGE_BY_VALUE_COPY_WARNING_END GCTIgnoreClangWarningEnd

//-Wliteral-conversion    implicit conversion from %0 to %1 changes value from %2 to %3
#define GCT_IGNORE_WLITERAL_CONVERSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wliteral-conversion)
#define GCT_IGNORE_WLITERAL_CONVERSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wliteral-range    magnitude of floating-point constant too large for type %0 maximum is %1
//-Wliteral-range    magnitude of floating-point constant too small for type %0 minimum is %1
#define GCT_IGNORE_WLITERAL_RANGE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wliteral-range)
#define GCT_IGNORE_WLITERAL_RANGE_WARNING_END GCTIgnoreClangWarningEnd

//-Wlogical-not-parentheses    logical not is only applied to the left hand side of this comparison
#define GCT_IGNORE_WLOGICAL_NOT_PARENTHESES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wlogical-not-parentheses)
#define GCT_IGNORE_WLOGICAL_NOT_PARENTHESES_WARNING_END GCTIgnoreClangWarningEnd

//-Wlogical-op-parentheses    '&&' within '||'
#define GCT_IGNORE_WLOGICAL_OP_PARENTHESES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wlogical-op-parentheses)
#define GCT_IGNORE_WLOGICAL_OP_PARENTHESES_WARNING_END GCTIgnoreClangWarningEnd

//-Wloop-analysis    variable%select{s| %1|s %1 and %2|s %1, %2, and %3|s %1, %2, %3, and %4}0 used in loop condition not modified in loop body
//-Wloop-analysis    variable %0 is %select{decremented|incremented}1 both in the loop header and in the loop body
#define GCT_IGNORE_WLOOP_ANALYSIS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wloop-analysis)
#define GCT_IGNORE_WLOOP_ANALYSIS_WARNING_END GCTIgnoreClangWarningEnd

//-Wmethod-signatures    conflicting parameter types in implementation of %0: %1 vs %2
//-Wmethod-signatures    conflicting return type in implementation of %0: %1 vs %2
#define GCT_IGNORE_WMETHOD_SIGNATURES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmethod-signatures)
#define GCT_IGNORE_WMETHOD_SIGNATURES_WARNING_END GCTIgnoreClangWarningEnd

//-Wmicrosoft    extra qualification on member %0
#define GCT_IGNORE_WMICROSOFT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmicrosoft)
#define GCT_IGNORE_WMICROSOFT_WARNING_END GCTIgnoreClangWarningEnd

//-Wmismatched-method-attributes    attributes on method implementation and its declaration must match
#define GCT_IGNORE_WMISMATCHED_METHOD_ATTRIBUTES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmismatched-method-attributes)
#define GCT_IGNORE_WMISMATCHED_METHOD_ATTRIBUTES_WARNING_END GCTIgnoreClangWarningEnd

//-Wmismatched-parameter-types    conflicting parameter types in implementation of %0%diff{: $ vs $|}1,2
#define GCT_IGNORE_WMISMATCHED_PARAMETER_TYPES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmismatched-parameter-types)
#define GCT_IGNORE_WMISMATCHED_PARAMETER_TYPES_WARNING_END GCTIgnoreClangWarningEnd

//-Wmismatched-return-types    conflicting return type in implementation of %0%diff{: $ vs $|}1,2
#define GCT_IGNORE_WMISMATCHED_RETURN_TYPES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmismatched-return-types)
#define GCT_IGNORE_WMISMATCHED_RETURN_TYPES_WARNING_END GCTIgnoreClangWarningEnd

//-Wmissing-braces    suggest braces around initialization of subobject
#define GCT_IGNORE_WMISSING_BRACES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmissing-braces)
#define GCT_IGNORE_WMISSING_BRACES_WARNING_END GCTIgnoreClangWarningEnd

//-Wmissing-declarations    '%0' ignored on this declaration
#define GCT_IGNORE_WMISSING_DECLARATIONS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmissing-declarations)
#define GCT_IGNORE_WMISSING_DECLARATIONS_WARNING_END GCTIgnoreClangWarningEnd

//-Wmissing-field-initializers    missing field '%0' initializer
#define GCT_IGNORE_WMISSING_FIELD_INITIALIZERS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmissing-field-initializers)
#define GCT_IGNORE_WMISSING_FIELD_INITIALIZERS_WARNING_END GCTIgnoreClangWarningEnd

//-Wmissing-method-return-type    method has no return type specified defaults to 'id'
#define GCT_IGNORE_WMISSING_METHOD_RETURN_TYPE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmissing-method-return-type)
#define GCT_IGNORE_WMISSING_METHOD_RETURN_TYPE_WARNING_END GCTIgnoreClangWarningEnd

//-Wmissing-noreturn    %select{function|method}0 %1 could be declared with attribute 'noreturn'
//-Wmissing-noreturn    block could be declared with attribute 'noreturn'
#define GCT_IGNORE_WMISSING_NORETURN_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmissing-noreturn)
#define GCT_IGNORE_WMISSING_NORETURN_WARNING_END GCTIgnoreClangWarningEnd

//-Wmissing-prototypes    no previous prototype for function %0
#define GCT_IGNORE_WMISSING_PROTOTYPES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmissing-prototypes)
#define GCT_IGNORE_WMISSING_PROTOTYPES_WARNING_END GCTIgnoreClangWarningEnd

//-Wmissing-variable-declarations    no previous extern declaration for non-static variable %0
#define GCT_IGNORE_WMISSING_VARIABLE_DECLARATIONS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmissing-variable-declarations)
#define GCT_IGNORE_WMISSING_VARIABLE_DECLARATIONS_WARNING_END GCTIgnoreClangWarningEnd

//-Wmultiple-move-vbase    defaulted move assignment operator of %0 will move assign virtual base class %1 multiple times
#define GCT_IGNORE_WMULTIPLE_MOVE_VBASE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmultiple-move-vbase)
#define GCT_IGNORE_WMULTIPLE_MOVE_VBASE_WARNING_END GCTIgnoreClangWarningEnd

//-Wnested-anon-types    anonymous types declared in an anonymous union/struct are an extension
#define GCT_IGNORE_WNESTED_ANON_TYPES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wnested-anon-types)
#define GCT_IGNORE_WNESTED_ANON_TYPES_WARNING_END GCTIgnoreClangWarningEnd

//-Wno-typedef-redefinition    Redefinition of typedef '%0' is a C11 feature
#define GCT_IGNORE_WNO_TYPEDEF_REDEFINITION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wno-typedef-redefinition)
#define GCT_IGNORE_WNO_TYPEDEF_REDEFINITION_WARNING_END GCTIgnoreClangWarningEnd

//-Wnon-literal-null-conversion    "expression which evaluates to zero treated as a null pointer constant of " "type %0
#define GCT_IGNORE_WNON_LITERAL_NULL_CONVERSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wnon-literal-null-conversion)
#define GCT_IGNORE_WNON_LITERAL_NULL_CONVERSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wnon-pod-varargs    second argument to 'va_arg' is of ARC ownership-qualified type %0
//-Wnon-pod-varargs    cannot pass %select{non-POD|non-trivial}0 object of type %1 to variadic %select{function|block|method|constructor}2 expected type from format string was %3
//-Wnon-pod-varargs    second argument to 'va_arg' is of non-POD type %0
//-Wnon-pod-varargs    cannot pass object of %select{non-POD|non-trivial}0 type %1 through variadic %select{function|block|method|constructor}2 call will abort at runtime
#define GCT_IGNORE_WNON_POD_VARARGS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wnon-pod-varargs)
#define GCT_IGNORE_WNON_POD_VARARGS_WARNING_END GCTIgnoreClangWarningEnd

//-Wnon-virtual-dtor    %0 has virtual functions but non-virtual destructor
#define GCT_IGNORE_WNON_VIRTUAL_DTOR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wnon-virtual-dtor)
#define GCT_IGNORE_WNON_VIRTUAL_DTOR_WARNING_END GCTIgnoreClangWarningEnd

//-Wnonnull    null passed to a callee which requires a non-null argument
#define GCT_IGNORE_WNONNULL_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wnonnull)
#define GCT_IGNORE_WNONNULL_WARNING_END GCTIgnoreClangWarningEnd

//-Wnull-arithmetic    use of NULL in arithmetic operation
//-Wnull-arithmetic    comparison between NULL and non-pointer %select{(%1 and NULL)|(NULL and %1)}0
#define GCT_IGNORE_WNULL_ARITHMETIC_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wnull-arithmetic)
#define GCT_IGNORE_WNULL_ARITHMETIC_WARNING_END GCTIgnoreClangWarningEnd

//-Wnull-dereference    indirection of non-volatile null pointer will be deleted, not trap
#define GCT_IGNORE_WNULL_DEREFERENCE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wnull-dereference)
#define GCT_IGNORE_WNULL_DEREFERENCE_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-autosynthesis-property-ivar-name-match    autosynthesized property %0 will use %select{|synthesized}1 instance variable %2, not existing instance variable %3
#define GCT_IGNORE_WOBJC_AUTOSYNTHESIS_PROPERTY_IVAR_NAME_MATCH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-autosynthesis-property-ivar-name-match)
#define GCT_IGNORE_WOBJC_AUTOSYNTHESIS_PROPERTY_IVAR_NAME_MATCH_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-forward-class-redefinition    redefinition of forward class %0 of a typedef name of an object type is ignored
#define GCT_IGNORE_WOBJC_FORWARD_CLASS_REDEFINITION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-forward-class-redefinition)
#define GCT_IGNORE_WOBJC_FORWARD_CLASS_REDEFINITION_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-interface-ivars    declaration of instance variables in the interface is deprecated
#define GCT_IGNORE_WOBJC_INTERFACE_IVARS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-interface-ivars)
#define GCT_IGNORE_WOBJC_INTERFACE_IVARS_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-literal-compare    direct comparison of %select{an array literal|a dictionary literal|a numeric literal|a boxed expression|}0 has undefined behavior
#define GCT_IGNORE_WOBJC_LITERAL_COMPARE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-literal-compare)
#define GCT_IGNORE_WOBJC_LITERAL_COMPARE_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-literal-missing-atsign    string literal must be prefixed by '@'
#define GCT_IGNORE_WOBJC_LITERAL_MISSING_ATSIGN_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-literal-missing-atsign)
#define GCT_IGNORE_WOBJC_LITERAL_MISSING_ATSIGN_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-method-access    instance method %objcinstance0 not found (return type defaults to 'id') did you mean %objcinstance2?
//-Wobjc-method-access    class method %objcclass0 not found (return type defaults to 'id') did you mean %objcclass2?
//-Wobjc-method-access    instance method %objcinstance0 not found (return type defaults to 'id')
//-Wobjc-method-access    instance method %0 is being used on 'Class' which is not in the root class
//-Wobjc-method-access    class method %objcclass0 not found (return type defaults to 'id')
//-Wobjc-method-access    instance method %0 found instead of class method %1
#define GCT_IGNORE_WOBJC_METHOD_ACCESS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-method-access)
#define GCT_IGNORE_WOBJC_METHOD_ACCESS_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-missing-property-synthesis    "auto property synthesis is synthesizing property not explicitly synthesized
#define GCT_IGNORE_WOBJC_MISSING_PROPERTY_SYNTHESIS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-missing-property-synthesis)
#define GCT_IGNORE_WOBJC_MISSING_PROPERTY_SYNTHESIS_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-missing-super-calls    method possibly missing a [super %0] call
#define GCT_IGNORE_WOBJC_MISSING_SUPER_CALLS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-missing-super-calls)
#define GCT_IGNORE_WOBJC_MISSING_SUPER_CALLS_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-noncopy-retain-block-property    "retain'ed block property does not copy the block " "- use copy attribute instead
#define GCT_IGNORE_WOBJC_NONCOPY_RETAIN_BLOCK_PROPERTY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-noncopy-retain-block-property)
#define GCT_IGNORE_WOBJC_NONCOPY_RETAIN_BLOCK_PROPERTY_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-nonunified-exceptions    can not catch an exception thrown with @throw in C++ in the non-unified exception model
#define GCT_IGNORE_WOBJC_NONUNIFIED_EXCEPTIONS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-nonunified-exceptions)
#define GCT_IGNORE_WOBJC_NONUNIFIED_EXCEPTIONS_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-property-implementation    property %0 requires method %1 to be defined - use @dynamic or provide a method implementation in this category
//-Wobjc-property-implementation    property %0 requires method %1 to be defined - use @synthesize, @dynamic or provide a method implementation in this class implementation
#define GCT_IGNORE_WOBJC_PROPERTY_IMPLEMENTATION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-property-implementation)
#define GCT_IGNORE_WOBJC_PROPERTY_IMPLEMENTATION_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-property-implicit-mismatch    "primary property declaration is implicitly strong while redeclaration in class extension is weak
#define GCT_IGNORE_WOBJC_PROPERTY_IMPLICIT_MISMATCH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-property-implicit-mismatch)
#define GCT_IGNORE_WOBJC_PROPERTY_IMPLICIT_MISMATCH_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-property-matches-cocoa-ownership-rule    property's synthesized getter follows Cocoa naming convention for returning 'owned' objects
#define GCT_IGNORE_WOBJC_PROPERTY_MATCHES_COCOA_OWNERSHIP_RULE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-property-matches-cocoa-ownership-rule)
#define GCT_IGNORE_WOBJC_PROPERTY_MATCHES_COCOA_OWNERSHIP_RULE_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-property-no-attribute    no 'assign', 'retain', or 'copy' attribute is specified - 'assign' is assumed
//-Wobjc-property-no-attribute    default property attribute 'assign' not appropriate for non-GC object
#define GCT_IGNORE_WOBJC_PROPERTY_NO_ATTRIBUTE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-property-no-attribute)
#define GCT_IGNORE_WOBJC_PROPERTY_NO_ATTRIBUTE_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-property-synthesis    auto property synthesis will not synthesize property '%0' because it is 'readwrite' but it will be synthesized 'readonly' via another property
//-Wobjc-property-synthesis    "auto property synthesis will not synthesize property '%0' because it cannot share an ivar with another synthesized property
#define GCT_IGNORE_WOBJC_PROPERTY_SYNTHESIS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-property-synthesis)
#define GCT_IGNORE_WOBJC_PROPERTY_SYNTHESIS_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-protocol-method-implementation    category is implementing a method which will also be implemented by its primary class
#define GCT_IGNORE_WOBJC_PROTOCOL_METHOD_IMPLEMENTATION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-protocol-method-implementation)
#define GCT_IGNORE_WOBJC_PROTOCOL_METHOD_IMPLEMENTATION_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-protocol-property-synthesis    auto property synthesis will not synthesize property declared in a protocol
#define GCT_IGNORE_WOBJC_PROTOCOL_PROPERTY_SYNTHESIS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-protocol-property-synthesis)
#define GCT_IGNORE_WOBJC_PROTOCOL_PROPERTY_SYNTHESIS_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-redundant-literal-use    using %0 with a literal is redundant
#define GCT_IGNORE_WOBJC_REDUNDANT_LITERAL_USE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-redundant-literal-use)
#define GCT_IGNORE_WOBJC_REDUNDANT_LITERAL_USE_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-root-class    class %0 defined without specifying a base class
#define GCT_IGNORE_WOBJC_ROOT_CLASS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-root-class)
#define GCT_IGNORE_WOBJC_ROOT_CLASS_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-string-compare    direct comparison of a string literal has undefined behavior
#define GCT_IGNORE_WOBJC_STRING_COMPARE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-string-compare)
#define GCT_IGNORE_WOBJC_STRING_COMPARE_WARNING_END GCTIgnoreClangWarningEnd

//-Wobjc-string-concatenation    concatenated NSString literal for an NSArray expression - possibly missing a comma
#define GCT_IGNORE_WOBJC_STRING_CONCATENATION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wobjc-string-concatenation)
#define GCT_IGNORE_WOBJC_STRING_CONCATENATION_WARNING_END GCTIgnoreClangWarningEnd

//-Wover-aligned    type %0 requires %1 bytes of alignment and the default allocator only guarantees %2 bytes
#define GCT_IGNORE_WOVER_ALIGNED_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wover-aligned)
#define GCT_IGNORE_WOVER_ALIGNED_WARNING_END GCTIgnoreClangWarningEnd

//-Woverloaded-shift-op-parentheses    overloaded operator %select{|}0 has lower precedence than comparison operator
#define GCT_IGNORE_WOVERLOADED_SHIFT_OP_PARENTHESES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Woverloaded-shift-op-parentheses)
#define GCT_IGNORE_WOVERLOADED_SHIFT_OP_PARENTHESES_WARNING_END GCTIgnoreClangWarningEnd

//-Woverloaded-virtual    %q0 hides overloaded virtual %select{function|functions}1
#define GCT_IGNORE_WOVERLOADED_VIRTUAL_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Woverloaded-virtual)
#define GCT_IGNORE_WOVERLOADED_VIRTUAL_WARNING_END GCTIgnoreClangWarningEnd

//-Woverriding-method-mismatch    conflicting distributed object modifiers on parameter type in declaration of %0
//-Woverriding-method-mismatch    conflicting parameter types in declaration of %0: %1 vs %2
//-Woverriding-method-mismatch    conflicting variadic declaration of method and its implementation
//-Woverriding-method-mismatch    conflicting distributed object modifiers on return type in declaration of %0
//-Woverriding-method-mismatch    conflicting parameter types in declaration of %0%diff{: $ vs $|}1,2
//-Woverriding-method-mismatch    conflicting return type in declaration of %0%diff{: $ vs $|}1,2
//-Woverriding-method-mismatch    conflicting return type in declaration of %0: %1 vs %2
#define GCT_IGNORE_WOVERRIDING_METHOD_MISMATCH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Woverriding-method-mismatch)
#define GCT_IGNORE_WOVERRIDING_METHOD_MISMATCH_WARNING_END GCTIgnoreClangWarningEnd

//-Wpacked    packed attribute is unnecessary for %0
//-Wpadded    padding %select{struct|interface|class}0 %1 with %2 %select{byte|bit}3%select{|s}4 to align anonymous bit-field
//-Wpadded    padding %select{struct|interface|class}0 %1 with %2 %select{byte|bit}3%select{|s}4 to align %5
//-Wpadded    padding size of %0 with %1 %select{byte|bit}2%select{|s}3 to alignment boundary
#define GCT_IGNORE_WPACKED_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wpadded)
#define GCT_IGNORE_WPACKED_WARNING_END GCTIgnoreClangWarningEnd

//-Wparentheses    using the result of an assignment as a condition without parentheses
//-Wparentheses    %0 has lower precedence than %1 %1 will be evaluated first
//-Wparentheses    operator '?:' has lower precedence than '%0' '%0' will be evaluated first
#define GCT_IGNORE_WPARENTHESE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wparentheses)
#define GCT_IGNORE_WPARENTHESE_WARNING_END GCTIgnoreClangWarningEnd

//-Wparentheses-equality    equality comparison with extraneous parentheses
#define GCT_IGNORE_WPARENTHESE_EQUALITY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wparentheses-equality)
#define GCT_IGNORE_WPARENTHESE_EQUALITY_WARNING_END GCTIgnoreClangWarningEnd

//-Wpointer-arith    subtraction of pointers to type %0 of zero size has undefined behavior
#define GCT_IGNORE_WPOINTER_ARITH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wpointer-arith)
#define GCT_IGNORE_WPOINTER_ARITH_WARNING_END GCTIgnoreClangWarningEnd

//-Wpredefined-identifier-outside-function    predefined identifier is only valid inside function
#define GCT_IGNORE_WPREDEFINED_IDENTIFIER_OUTSIDE_FUNCTION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wpredefined-identifier-outside-function)
#define GCT_IGNORE_WPREDEFINED_IDENTIFIER_OUTSIDE_FUNCTION_WARNING_END GCTIgnoreClangWarningEnd

//-Wprivate-extern    use of __private_extern__ on a declaration may not produce external symbol private to the linkage unit and is deprecated
#define GCT_IGNORE_WPRIVATE_EXTERN_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wprivate-extern)
#define GCT_IGNORE_WPRIVATE_EXTERN_WARNING_END GCTIgnoreClangWarningEnd

//-Wprotocol    method %0 in protocol not implemented
#define GCT_IGNORE_WPROTOCOL_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wprotocol)
#define GCT_IGNORE_WPROTOCOL_WARNING_END GCTIgnoreClangWarningEnd

//-Wprotocol-property-synthesis-ambiguity    property of type %0 was selected for synthesis
#define GCT_IGNORE_WPROTOCOL_PROPERTY_SYNTHESIS_AMBIGUITY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wprotocol-property-synthesis-ambiguity)
#define GCT_IGNORE_WPROTOCOL_PROPERTY_SYNTHESIS_AMBIGUITY_WARNING_END GCTIgnoreClangWarningEnd

//-Wreadonly-iboutlet-property    readonly IBOutlet property '%0' when auto-synthesized may not work correctly with 'nib' loader
#define GCT_IGNORE_WREADONLY_IBOUTLET_PROPERTY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wreadonly-iboutlet-property)
#define GCT_IGNORE_WREADONLY_IBOUTLET_PROPERTY_WARNING_END GCTIgnoreClangWarningEnd

//-Wreadonly-setter-attrs    property attributes '%0' and '%1' are mutually exclusive
#define GCT_IGNORE_WREADONLY_SETTER_ATTRS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wreadonly-setter-attrs)
#define GCT_IGNORE_WREADONLY_SETTER_ATTRS_WARNING_END GCTIgnoreClangWarningEnd

//-Wreceiver-expr    receiver type %0 is not 'id' or interface pointer, consider casting it to 'id'
#define GCT_IGNORE_WRECEIVER_EXPR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wreceiver-expr)
#define GCT_IGNORE_WRECEIVER_EXPR_WARNING_END GCTIgnoreClangWarningEnd

//-Wreceiver-forward-class    receiver type %0 for instance message is a forward declaration
#define GCT_IGNORE_WRECEIVER_FORWARD_CLASS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wreceiver-forward-class)
#define GCT_IGNORE_WRECEIVER_FORWARD_CLASS_WARNING_END GCTIgnoreClangWarningEnd

//-Wreceiver-is-weak    "weak %select{receiver|property|implicit property}0 may be unpredictably set to nil
#define GCT_IGNORE_WRECEIVER_IS_WEAK_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wreceiver-is-weak)
#define GCT_IGNORE_WRECEIVER_IS_WEAK_WARNING_END GCTIgnoreClangWarningEnd

//-Wreinterpret-base-class    'reinterpret_cast' %select{from|to}3 class %0 %select{to|from}3 its %select{virtual base|base at non-zero offset}2 %1 behaves differently from 'static_cast'
#define GCT_IGNORE_WREINTERPRET_BASE_CLASS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wreinterpret-base-class)
#define GCT_IGNORE_WREINTERPRET_BASE_CLASS_WARNING_END GCTIgnoreClangWarningEnd

//-Wreorder    %select{field|base class}0 %1 will be initialized after %select{field|base}2 %3
#define GCT_IGNORE_WREORDER_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wreorder)
#define GCT_IGNORE_WREORDER_WARNING_END GCTIgnoreClangWarningEnd

//-Wrequires-super-attribute    %0 attribute cannot be applied to %select{methods in protocols|dealloc}1
#define GCT_IGNORE_WREQUIRES_SUPER_ATTRIBUTE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wrequires-super-attribute)
#define GCT_IGNORE_WREQUIRES_SUPER_ATTRIBUTE_WARNING_END GCTIgnoreClangWarningEnd

//-Wreturn-stack-address    returning address of local temporary object
//-Wreturn-stack-address    returning address of label, which is local
//-Wreturn-stack-address    address of stack memory associated with local variable %0 returned
//-Wreturn-stack-address    reference to stack memory associated with local variable %0 returned
//-Wreturn-stack-address    returning reference to local temporary object
#define GCT_IGNORE_WRETURN_STACK_ADDRESS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wreturn-stack-address)
#define GCT_IGNORE_WRETURN_STACK_ADDRESS_WARNING_END GCTIgnoreClangWarningEnd

//-Wreturn-type    control may reach end of non-void function
//-Wreturn-type    non-void %select{function|method}1 %0 should return a value, DefaultError
//-Wreturn-type    control reaches end of non-void function
#define GCT_IGNORE_WRETURN_TYPE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wreturn-type)
#define GCT_IGNORE_WRETURN_TYPE_WARNING_END GCTIgnoreClangWarningEnd

//-Wreturn-type-c-linkage    %0 has C-linkage specified, but returns incomplete type %1 which could be incompatible with C
//-Wreturn-type-c-linkage    %0 has C-linkage specified, but returns user-defined type %1 which is incompatible with C
#define GCT_IGNORE_WRETURN_TYPE_C_LINKAGE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wreturn-type-c-linkage)
#define GCT_IGNORE_WRETURN_TYPE_C_LINKAGE_WARNING_END GCTIgnoreClangWarningEnd

//-Wsection    section does not match previous declaration
#define GCT_IGNORE_WSECTION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsection)
#define GCT_IGNORE_WSECTION_WARNING_END GCTIgnoreClangWarningEnd

//-Wselector    creating selector for nonexistent method %0
#define GCT_IGNORE_WSELECTOR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wselector)
#define GCT_IGNORE_WSELECTOR_WARNING_END GCTIgnoreClangWarningEnd

//-Wselector-type-mismatch    multiple selectors named %0 found
#define GCT_IGNORE_WSELECTOR_TYPE_MISMATCH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wselector-type-mismatch)
#define GCT_IGNORE_WSELECTOR_TYPE_MISMATCH_WARNING_END GCTIgnoreClangWarningEnd

//-Wself-assign    explicitly assigning a variable of type %0 to itself
#define GCT_IGNORE_WSELF_ASSIGN_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wself-assign)
#define GCT_IGNORE_WSELF_ASSIGN_WARNING_END GCTIgnoreClangWarningEnd

//-Wself-assign-field    assigning %select{field|instance variable}0 to itself
#define GCT_IGNORE_WSELF_ASSIGN_FIELD_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wself-assign-field)
#define GCT_IGNORE_WSELF_ASSIGN_FIELD_WARNING_END GCTIgnoreClangWarningEnd

//-Wsentinel    "missing sentinel in %select{function call|method dispatch|block call}0
//-Wsentinel    not enough variable arguments in %0 declaration to fit a sentinel
#define GCT_IGNORE_WSENTINEL_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsentinel)
#define GCT_IGNORE_WSENTINEL_WARNING_END GCTIgnoreClangWarningEnd

//-Wshadow    declaration shadows a %select{" "local variable|" "variable in %2|" "static data member of %2|" "field of %2}1
#define GCT_IGNORE_WSHADOW_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wshadow)
#define GCT_IGNORE_WSHADOW_WARNING_END GCTIgnoreClangWarningEnd

//-Wshadow-ivar    local declaration of %0 hides instance variable
#define GCT_IGNORE_WSHADOW_IVAR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wshadow-ivar)
#define GCT_IGNORE_WSHADOW_IVAR_WARNING_END GCTIgnoreClangWarningEnd

//-Wshift-count-negative    shift count is negative
#define GCT_IGNORE_WSHIFT_COUNT_NEGATIVE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wshift-count-negative)
#define GCT_IGNORE_WSHIFT_COUNT_NEGATIVE_WARNING_END GCTIgnoreClangWarningEnd

//-Wshift-count-overflow    shift count = width of type
#define GCT_IGNORE_WSHIFT_COUNT_OVERFLOW_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wshift-count-overflow)
#define GCT_IGNORE_WSHIFT_COUNT_OVERFLOW_WARNING_END GCTIgnoreClangWarningEnd

//-Wshift-op-parentheses    operator '%0' has lower precedence than '%1' '%1' will be evaluated first
#define GCT_IGNORE_WSHIFT_OP_PARENTHESES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wshift-op-parentheses)
#define GCT_IGNORE_WSHIFT_OP_PARENTHESES_WARNING_END GCTIgnoreClangWarningEnd

//-Wshift-overflow    signed shift result (%0) requires %1 bits to represent, but %2 only has %3 bits
#define GCT_IGNORE_WSHIFT_OVERFLOW_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wshift-overflow)
#define GCT_IGNORE_WSHIFT_OVERFLOW_WARNING_END GCTIgnoreClangWarningEnd

//-Wshift-sign-overflow    signed shift result (%0) sets the sign bit of the shift expression's type (%1) and becomes negative
#define GCT_IGNORE_WSHIFT_SIGN_OVERFLOW_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wshift-sign-overflow)
#define GCT_IGNORE_WSHIFT_SIGN_OVERFLOW_WARNING_END GCTIgnoreClangWarningEnd

//-Wshorten-64-to-32    implicit conversion loses integer precision: %0 to %1
#define GCT_IGNORE_WSHORTEH_64_TO_32_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wshorten-64-to-32)
#define GCT_IGNORE_WSHORTEH_64_TO_32_WARNING_END GCTIgnoreClangWarningEnd

//-Wsign-compare    comparison of integers of different signs: %0 and %1
#define GCT_IGNORE_WSIGN_COMPARE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsign-compare)
#define GCT_IGNORE_WSIGN_COMPARE_WARNING_END GCTIgnoreClangWarningEnd

//-Wsign-conversion    implicit conversion changes signedness: %0 to %1
//-Wsign-conversion    operand of ? changes signedness: %0 to %1
#define GCT_IGNORE_WSIGN_CONVERSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsign-conversion)
#define GCT_IGNORE_WSIGN_CONVERSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wsizeof-array-argument    sizeof on array function parameter will return size of %0 instead of %1
#define GCT_IGNORE_WSIZEOF_ARRAY_ARGUMENT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsizeof-array-argument)
#define GCT_IGNORE_WSIZEOF_ARRAY_ARGUMENT_WARNING_END GCTIgnoreClangWarningEnd

//-Wsizeof-array-decay    sizeof on pointer operation will return size of %0 instead of %1
#define GCT_IGNORE_WSIZEFO_ARRAY_DECAY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsizeof-array-decay)
#define GCT_IGNORE_WSIZEFO_ARRAY_DECAY_WARNING_END GCTIgnoreClangWarningEnd

//-Wsizeof-pointer-memaccess    '%0' call operates on objects of type %1 while the size is based on a " "different type %2
//-Wsizeof-pointer-memaccess    argument to 'sizeof' in %0 call is the same pointer type %1 as the %select{destination|source}2 expected %3 or an explicit length
#define GCT_IGNORE_WSIZEFO_POINTER_MEMACCESS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsizeof-pointer-memaccess)
#define GCT_IGNORE_WSIZEFO_POINTER_MEMACCESS_WARNING_END GCTIgnoreClangWarningEnd

//-Wsometimes-uninitialized    variable %0 is %select{used|captured}1 uninitialized whenever %select{'%3' condition is %select{true|false}4|'%3' loop %select{is entered|exits because its condition is false}4|'%3' loop %select{condition is true|exits because its condition is false}4|switch %3 is taken|its declaration is reached|%3 is called}2
#define GCT_IGNORE_WSOMETIMES_UNINITIALIZED_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsometimes-uninitialized)
#define GCT_IGNORE_WSOMETIMES_UNINITIALIZED_WARNING_END GCTIgnoreClangWarningEnd

//-Wstatic-local-in-inline    non-constant static local variable in inline function may be different in different files
#define GCT_IGNORE_WSTATIC_LOCAL_IN_INLINE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wstatic-local-in-inline)
#define GCT_IGNORE_WSTATIC_LOCAL_IN_INLINE_WARNING_END GCTIgnoreClangWarningEnd

//-Wstatic-self-init    static variable %0 is suspiciously used within its own initialization
#define GCT_IGNORE_WSTATIC_SELF_INIT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wstatic-self-init)
#define GCT_IGNORE_WSTATIC_SELF_INIT_WARNING_END GCTIgnoreClangWarningEnd

//-Wstrict-selector-match    multiple methods named %0 found
#define GCT_IGNORE_WSTRICT_SELECTOR_MATCH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wstrict-selector-match)
#define GCT_IGNORE_WSTRICT_SELECTOR_MATCH_WARNING_END GCTIgnoreClangWarningEnd

//-Wstring-compare    result of comparison against %select{a string literal|@encode}0 is unspecified (use strncmp instead)
#define GCT_IGNORE_WSTRING_COMPARE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wstring-compare)
#define GCT_IGNORE_WSTRING_COMPARE_WARNING_END GCTIgnoreClangWarningEnd

//-Wstring-conversion    implicit conversion turns string literal into bool: %0 to %1
#define GCT_IGNORE_WSTRING_CONVERSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wstring-conversion)
#define GCT_IGNORE_WSTRING_CONVERSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wstring-plus-char    adding %0 to a string pointer does not append to the string
#define GCT_IGNORE_WSTRING_PLUS_CHAR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wstring-plus-char)
#define GCT_IGNORE_WSTRING_PLUS_CHAR_WARNING_END GCTIgnoreClangWarningEnd

//-Wstring-plus-int    adding %0 to a string does not append to the string
#define GCT_IGNORE_WSTRING_PLUS_INT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wstring-plus-int)
#define GCT_IGNORE_WSTRING_PLUS_INT_WARNING_END GCTIgnoreClangWarningEnd

//-Wstrlcpy-strlcat-size    size argument in %0 call appears to be size of the source expected the size of the destination
#define GCT_IGNORE_WSTRLCPY_STRLCAT_SIZE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wstrlcpy-strlcat-size)
#define GCT_IGNORE_WSTRLCPY_STRLCAT_SIZE_WARNING_END GCTIgnoreClangWarningEnd

//-Wstrncat-size    the value of the size argument in 'strncat' is too large, might lead to a " "buffer overflow
//-Wstrncat-size    size argument in 'strncat' call appears " "to be size of the source
//-Wstrncat-size    the value of the size argument to 'strncat' is wrong
#define GCT_IGNORE_WSTRNCAT_SIZE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wstrncat-size)
#define GCT_IGNORE_WSTRNCAT_SIZE_WARNING_END GCTIgnoreClangWarningEnd

//-Wsuper-class-method-mismatch    method parameter type %diff{$ does not match super class method parameter type $|does not match super class method parameter type}0,1
#define GCT_IGNORE_WSUPER_CLASS_METHOD_MISMATCH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsuper-class-method-mismatch)
#define GCT_IGNORE_WSUPER_CLASS_METHOD_MISMATCH_WARNING_END GCTIgnoreClangWarningEnd

//-Wswitch    overflow converting case value to switch condition type (%0 to %1)
//-Wswitch    case value not in enumerated type %0
//-Wswitch    %0 enumeration values not handled in switch: %1, %2, %3...
//-Wswitch    enumeration values %0 and %1 not handled in switch
//-Wswitch    enumeration value %0 not handled in switch
//-Wswitch    enumeration values %0, %1, and %2 not handled in switch
#define GCT_IGNORE_WSWITCH_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wswitch)
#define GCT_IGNORE_WSWITCH_WARNING_END GCTIgnoreClangWarningEnd

//-Wswitch-enum    enumeration values %0, %1, and %2 not explicitly handled in switch
//-Wswitch-enum    enumeration values %0 and %1 not explicitly handled in switch
//-Wswitch-enum    %0 enumeration values not explicitly handled in switch: %1, %2, %3...
//-Wswitch-enum    enumeration value %0 not explicitly handled in switch
#define GCT_IGNORE_WSWITCH_ENUM_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wswitch-enum)
#define GCT_IGNORE_WSWITCH_ENUM_WARNING_END GCTIgnoreClangWarningEnd

//-Wtautological-compare    comparison of %0 unsigned%select{| enum}2 expression is always %1
//-Wtautological-compare    %select{self-|array }0comparison always evaluates to %select{false|true|a constant}1
//-Wtautological-compare    comparison of unsigned%select{| enum}2 expression %0 is always %1
#define GCT_IGNORE_WTAUTOLOGICAL_COMPARE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wtautological-compare)
#define GCT_IGNORE_WTAUTOLOGICAL_COMPARE_WARNING_END GCTIgnoreClangWarningEnd

//-Wtautological-constant-out-of-range-compare    comparison of constant %0 with expression of type %1 is always %select{false|true}2
#define GCT_IGNORE_WTAUTOLOGICAL_CONSTANT_OUT_OF_RANGE_COMPARE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wtautological-constant-out-of-range-compare)
#define GCT_IGNORE_WTAUTOLOGICAL_CONSTANT_OUT_OF_RANGE_COMPARE_WARNING_END GCTIgnoreClangWarningEnd

//-Wthread-safety-analysis    locking '%0' that is already locked
//-Wthread-safety-analysis    cannot call function '%0' while mutex '%1' is locked
//-Wthread-safety-analysis    %select{reading|writing}2 the value pointed to by '%0' requires locking %select{'%1'|'%1' exclusively}2
//-Wthread-safety-analysis    unlocking '%0' that was not locked
//-Wthread-safety-analysis    mutex '%0' is locked exclusively and shared in the same scope
//-Wthread-safety-analysis    calling function '%0' requires %select{shared|exclusive}2 lock on '%1'
//-Wthread-safety-analysis    %select{reading|writing}2 variable '%0' requires locking %select{'%1'|'%1' exclusively}2
//-Wthread-safety-analysis    cannot resolve lock expression
//-Wthread-safety-analysis    expecting mutex '%0' to be locked at the end of function
//-Wthread-safety-analysis    mutex '%0' is not locked on every path through here
//-Wthread-safety-analysis    %select{reading|writing}1 the value pointed to by '%0' requires locking %select{any mutex|any mutex exclusively}1
//-Wthread-safety-analysis    %select{reading|writing}1 variable '%0' requires locking %select{any mutex|any mutex exclusively}1
//-Wthread-safety-analysis    mutex '%0' is still locked at the end of function
//-Wthread-safety-analysis    expecting mutex '%0' to be locked at start of each loop
#define GCT_IGNORE_WTHREAD_SAFETY_ANALYSIS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wthread-safety-analysis)
#define GCT_IGNORE_WTHREAD_SAFETY_ANALYSIS_WARNING_END GCTIgnoreClangWarningEnd


//-Wthread-safety-attributes    ignoring %0 attribute because its argument is invalid
//-Wthread-safety-attributes    %0 attribute only applies to %select{fields and global variables|functions and methods|classes and structs}1
//-Wthread-safety-attributes    %0 attribute requires arguments that are class type or point to class type type here is '%1'
//-Wthread-safety-attributes    %0 attribute can only be applied in a context annotated with 'lockable' attribute
//-Wthread-safety-attributes    %0 attribute requires arguments whose type is annotated with 'lockable' attribute type here is '%1'
//-Wthread-safety-attributes    '%0' only applies to pointer types type here is %1
#define GCT_IGNORE_WTHREAD_SAFETY_ATTRIBUTES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wthread-safety-attributes)
#define GCT_IGNORE_WTHREAD_SAFETY_ATTRIBUTES_WARNING_END GCTIgnoreClangWarningEnd

//-Wthread-safety-beta    Thread safety beta warning.
#define GCT_IGNORE_WTHREAD_SAFETY_BETA_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wthread-safety-beta)
#define GCT_IGNORE_WTHREAD_SAFETY_BETA_WARNING_END GCTIgnoreClangWarningEnd

//-Wthread-safety-precise    %select{reading|writing}2 the value pointed to by '%0' requires locking %select{'%1'|'%1' exclusively}2
//-Wthread-safety-precise    %select{reading|writing}2 variable '%0' requires locking %select{'%1'|'%1' exclusively}2
//-Wthread-safety-precise    calling function '%0' requires %select{shared|exclusive}2 lock on '%1'
#define GCT_IGNORE_WTHREAD_SAFETY_PRECISE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wthread-safety-precise)
#define GCT_IGNORE_WTHREAD_SAFETY_PRECISE_WARNING_END GCTIgnoreClangWarningEnd

//-Wtype-safety    this type tag was not designed to be used with this function
//-Wtype-safety    specified %0 type tag requires a null pointer
//-Wtype-safety    argument type %0 doesn't match specified '%1' type tag %select{that requires %3|}2
#define GCT_IGNORE_WTYPE_SAFETY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wtype-safety)
#define GCT_IGNORE_WTYPE_SAFETY_WARNING_END GCTIgnoreClangWarningEnd

//-Wundeclared-selector    undeclared selector %0 did you mean %1?
//-Wundeclared-selector    undeclared selector %0
#define GCT_IGNORE_WUNDECLARED_SELECTOR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wundeclared-selector)
#define GCT_IGNORE_WUNDECLARED_SELECTOR_WARNING_END GCTIgnoreClangWarningEnd

//-Wundefined-inline    inline function %q0 is not defined
#define GCT_IGNORE_WUNDEFINED_INLINE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wundefined-inline)
#define GCT_IGNORE_WUNDEFINED_INLINE_WARNING_END GCTIgnoreClangWarningEnd

//-Wundefined-internal    %select{function|variable}0 %q1 has internal linkage but is not defined
#define GCT_IGNORE_WUNDEFINED_INTERNAL_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wundefined-internal)
#define GCT_IGNORE_WUNDEFINED_INTERNAL_WARNING_END GCTIgnoreClangWarningEnd

//-Wundefined-reinterpret-cast    dereference of type %1 that was reinterpret_cast from type %0 has undefined behavior
//-Wundefined-reinterpret-cast    reinterpret_cast from %0 to %1 has undefined behavior
#define GCT_IGNORE_WUNDEFINED_REINTERPRET_CAST_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wundefined-reinterpret-cast)
#define GCT_IGNORE_WUNDEFINED_REINTERPRET_CAST_WARNING_END GCTIgnoreClangWarningEnd

//-Wuninitialized    reference %0 is not yet bound to a value when used within its own initialization
//-Wuninitialized    field %0 is uninitialized when used here
//-Wuninitialized    block pointer variable %0 is uninitialized when captured by block
//-Wuninitialized    variable %0 is uninitialized when used within its own initialization
//-Wuninitialized    variable %0 is uninitialized when %select{used here|captured by block}1
//-Wuninitialized    reference %0 is not yet bound to a value when used here
#define GCT_IGNORE_WUNINITIALIZED_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wuninitialized)
#define GCT_IGNORE_WUNINITIALIZED_WARNING_END GCTIgnoreClangWarningEnd

//-Wunneeded-internal-declaration    %select{function|variable}0 %1 is not needed and will not be emitted
//-Wunneeded-internal-declaration    'static' function %0 declared in header file should be declared 'static inline'
#define GCT_IGNORE_WUNNEEDED_INTERNAL_DECLARATION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunneeded-internal-declaration)
#define GCT_IGNORE_WUNNEEDED_INTERNAL_DECLARATION_WARNING_END GCTIgnoreClangWarningEnd

//-Wunneeded-member-function    member function %0 is not needed and will not be emitted
#define GCT_IGNORE_WUNNEEDED_MEMBER_FUNCTION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunneeded-member-function)
#define GCT_IGNORE_WUNNEEDED_MEMBER_FUNCTION_WARNING_END GCTIgnoreClangWarningEnd

//-Wunreachable-code    will never be executed
#define GCT_IGNORE_WUNREACHABLE_CODE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunreachable-code)
#define GCT_IGNORE_WUNREACHABLE_CODE_WARNING_END GCTIgnoreClangWarningEnd

//-Wunsequenced    multiple unsequenced modifications to %0
//-Wunsequenced    unsequenced modification and access to %0
#define GCT_IGNORE_WUNSEQUENCED_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunsequenced)
#define GCT_IGNORE_WUNSEQUENCED_WARNING_END GCTIgnoreClangWarningEnd

//-Wunsupported-friend    dependent nested name specifier '%0' for friend template declaration is not supported ignoring this friend declaration
//-Wunsupported-friend    dependent nested name specifier '%0' for friend class declaration is not supported turning off access control for %1
#define GCT_IGNORE_WUNSUPPORTED_FRIEND_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunsupported-friend)
#define GCT_IGNORE_WUNSUPPORTED_FRIEND_WARNING_END GCTIgnoreClangWarningEnd

//-Wunsupported-visibility    target does not support 'protected' visibility using 'default'
#define GCT_IGNORE_WUNSUPPORTED_VISIBILITY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunsupported-visibility)
#define GCT_IGNORE_WUNSUPPORTED_VISIBILITY_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-comparison    %select{equality|inequality}0 comparison result unused
#define GCT_IGNORE_WUNUSED_COMPARISON_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-comparison)
#define GCT_IGNORE_WUNUSED_COMPARISON_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-const-variable    unused variable %0
#define GCT_IGNORE_WUNUSED_CONST_VARIABLE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-const-variable)
#define GCT_IGNORE_WUNUSED_CONST_VARIABLE_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-exception-parameter    unused exception parameter %0
#define GCT_IGNORE_WUNUSED_EXCEPTION_PARAMETER_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-exception-parameter)
#define GCT_IGNORE_WUNUSED_EXCEPTION_PARAMETER_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-function    unused function %0
#define GCT_IGNORE_WUNUSED_FUNCTION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-function)
#define GCT_IGNORE_WUNUSED_FUNCTION_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-label    unused label %0
#define GCT_IGNORE_WUNUSED_LABEL_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-label)
#define GCT_IGNORE_WUNUSED_LABEL_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-member-function    unused member function %0
#define GCT_IGNORE_WUNUSED_MEMBER_FUNCTION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-member-function)
#define GCT_IGNORE_WUNUSED_MEMBER_FUNCTION_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-parameter    unused parameter %0
#define GCT_IGNORE_WUNUSED_PARAMETER_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-parameter)
#define GCT_IGNORE_WUNUSED_PARAMETER_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-private-field    private field %0 is not used
#define GCT_IGNORE_WUNUSED_PRIVATE_FIELD_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-private-field)
#define GCT_IGNORE_WUNUSED_PRIVATE_FIELD_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-property-ivar    ivar %0 which backs the property is not referenced in this property's accessor
#define GCT_IGNORE_WUNUSED_PROPERTY_IVAR_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-property-ivar)
#define GCT_IGNORE_WUNUSED_PROPERTY_IVAR_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-result    ignoring return value of function declared with warn_unused_result attribute
#define GCT_IGNORE_WUNUSED_RESULT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-result)
#define GCT_IGNORE_WUNUSED_RESULT_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-value    ignoring return value of function declared with %0 attribute
//-Wunused-value    expression result unused should this cast be to 'void'?
//-Wunused-value    expression result unused
#define GCT_IGNORE_WUNUSED_VALUE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-value)
#define GCT_IGNORE_WUNUSED_VALUE_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-variable    unused variable %0
#define GCT_IGNORE_WUNUSED_VARIABLE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-variable)
#define GCT_IGNORE_WUNUSED_VARIABLE_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-volatile-lvalue    expression result unused assign into a variable to force a volatile load
#define GCT_IGNORE_WUNUSED_VOLATILE_LVALUE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-volatile-lvalue)
#define GCT_IGNORE_WUNUSED_VOLATILE_LVALUE_WARNING_END GCTIgnoreClangWarningEnd

//-Wused-but-marked-unused    %0 was marked unused but was used
#define GCT_IGNORE_WUSED_BUT_MARKED_UNUSED_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wused-but-marked-unused)
#define GCT_IGNORE_WUSED_BUT_MARKED_UNUSED_WARNING_END GCTIgnoreClangWarningEnd

//-Wuser-defined-literals    user-defined literal suffixes not starting with '_' are reserved%select{ no literal will invoke this operator|}0
#define GCT_IGNORE_WUSED_DEFINE_LITERALS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wuser-defined-literals)
#define GCT_IGNORE_WUSED_DEFINE_LITERALS_WARNING_END GCTIgnoreClangWarningEnd

//-Wvarargs    second parameter of 'va_start' not last named argument
//-Wvarargs    'va_start' has undefined behavior with reference types
//-Wvarargs    second argument to 'va_arg' is of promotable type %0 this va_arg has undefined behavior because arguments will be promoted to %1
#define GCT_IGNORE_WVARARGS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wvarargs)
#define GCT_IGNORE_WVARARGS_WARNING_END GCTIgnoreClangWarningEnd

//-Wvector-conversion    incompatible vector types %select{%diff{assigning to $ from $|assigning to different types}0,1|%diff{passing $ to parameter of type $|passing to parameter of different type}0,1|%diff{returning $ from a function with result type $|returning from function with different return type}0,1|%diff{converting $ to type $|converting between types}0,1|%diff{initializing $ with an expression of type $|initializing with expression of different type}0,1|%diff{sending $ to parameter of type $|sending to parameter of different type}0,1|%diff{casting $ to type $|casting between types}0,1}2
#define GCT_IGNORE_WVECTOR_CONVERSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wvector-conversion)
#define GCT_IGNORE_WVECTOR_CONVERSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wvexing-parse    parentheses were disambiguated as a function declaration
//-Wvexing-parse    empty parentheses interpreted as a function declaration
#define GCT_IGNORE_WVEXING_PARSE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wvexing-parse)
#define GCT_IGNORE_WVEXING_PARSE_WARNING_END GCTIgnoreClangWarningEnd

//-Wvisibility    declaration of %0 will not be visible outside of this function
//-Wvisibility    redefinition of %0 will not be visible outside of this function
#define GCT_IGNORE_WVISIBILITY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wvisibility)
#define GCT_IGNORE_WVISIBILITY_WARNING_END GCTIgnoreClangWarningEnd

//-Wvla    variable length array used
#define GCT_IGNORE_WVLA_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wvla)
#define GCT_IGNORE_WVLA_WARNING_END GCTIgnoreClangWarningEnd

//-Wvla-extension    variable length arrays are a C99 feature
#define GCT_IGNORE_WVLA_WXTENSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wvla-extension)
#define GCT_IGNORE_WVLA_WXTENSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wweak-template-vtables    explicit template instantiation %0 will emit a vtable in every translation unit
#define GCT_IGNORE_WWEAK_TEMPLATE_VTABLES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wweak-template-vtables)
#define GCT_IGNORE_WWEAK_TEMPLATE_VTABLES_WARNING_END GCTIgnoreClangWarningEnd

//-Wweak-vtables    %0 has no out-of-line virtual method definitions; its vtable will be emitted in every translation unit
#define GCT_IGNORE_WWEAK_VTABLES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wweak-vtables)
#define GCT_IGNORE_WWEAK_VTABLES_WARNING_END GCTIgnoreClangWarningEnd

#pragma mark - Lexer Warnings

//-W#pragma-messages    %0
#define GCT_IGNORE_WPRAGMA_MESSAGES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-W#pragma-messages)
#define GCT_IGNORE_WPRAGMA_MESSAGES_WARNING_END GCTIgnoreClangWarningEnd

//-W#warnings    %0
//-W#warnings    %0
#define GCT_IGNORE_WWARNINGS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-W#warnings)
#define GCT_IGNORE_WWARNINGS_WARNING_END GCTIgnoreClangWarningEnd

//-Wambiguous-macro    ambiguous expansion of macro %0
#define GCT_IGNORE_WAMBIGUOUS_MACRO_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wambiguous-macro)
#define GCT_IGNORE_WAMBIGUOUS_MACRO_WARNING_END GCTIgnoreClangWarningEnd

//-Wauto-import    treating #%select{include|import|include_next|__include_macros}0 as an import of module '%1'
#define GCT_IGNORE_WAUTO_IMPORT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wauto-import)
#define GCT_IGNORE_WAUTO_IMPORT_WARNING_END GCTIgnoreClangWarningEnd

//-Wbackslash-newline-escape    backslash and newline separated by space
#define GCT_IGNORE_WBACKSLASH_NEWLINE_ESCAPE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wbackslash-newline-escape)
#define GCT_IGNORE_WBACKSLASH_NEWLINE_ESCAPE_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++11-compat    identifier after literal will be treated as a user-defined literal suffix in C++11
//-Wc++11-compat    '%0' is a keyword in C++11
#define GCT_IGNORE_WC11_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++11-compat)
#define GCT_IGNORE_WC11_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++98-c++11-compat    digit separators are incompatible with C++ standards before C++1y
#define GCT_IGNORE_WC98_C11_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++98-c++11-compat)
#define GCT_IGNORE_WC98_C11_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++98-c++11-compat-pedantic    binary integer literals are incompatible with C++ standards before C++1y
#define GCT_IGNORE_WC98_C11_COMPAT_PEDANTIC_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++98-c++11-compat-pedantic)
#define GCT_IGNORE_WC98_C11_COMPAT_PEDANTIC_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++98-compat    raw string literals are incompatible with C++98
//-Wc++98-compat    unicode literals are incompatible with C++98
//-Wc++98-compat    universal character name referring to a control character is incompatible with C++98
//-Wc++98-compat    '::' is treated as digraph ':' (aka '[') followed by ':' in C++98
//-Wc++98-compat    using this character in an identifier is incompatible with C++98
//-Wc++98-compat    specifying character '%0' with a universal character name is incompatible with C++98
#define GCT_IGNORE_WC98_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++98-compat)
#define GCT_IGNORE_WC98_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++98-compat-pedantic    variadic macros are incompatible with C++98
//-Wc++98-compat-pedantic    #line number greater than 32767 is incompatible with C++98
//-Wc++98-compat-pedantic    C++98 requires newline at end of file
//-Wc++98-compat-pedantic    empty macro arguments are incompatible with C++98
#define GCT_IGNORE_WC98_COMPAT_PEDANTIC_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++98-compat-pedantic)
#define GCT_IGNORE_WC98_COMPAT_PEDANTIC_WARNING_END GCTIgnoreClangWarningEnd

//-Wc99-compat    unicode literals are incompatible with C99
//-Wc99-compat    %select{using this character in an identifier|starting an identifier with this character}0 is incompatible with C99
#define GCT_IGNORE_WC99_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc99-compa)
#define GCT_IGNORE_WC99_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wcomment    '/*' within block comment
//-Wcomment    escaped newline between */ characters at block comment end
#define GCT_IGNORE_WCOMMENT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wcomment)
#define GCT_IGNORE_WCOMMENT_WARNING_END GCTIgnoreClangWarningEnd

//-Wdisabled-macro-expansion    disabled expansion of recursive macro
#define GCT_IGNORE_WDISABLED_MACRO_EXPANSION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdisabled-macro-expansion)
#define GCT_IGNORE_WDISABLED_MACRO_EXPANSION_WARNING_END GCTIgnoreClangWarningEnd

//-Wheader-guard    %0 is used as a header guard here, followed by #define of a different macro
#define GCT_IGNORE_WHEADER_GUARD_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wheader-guard)
#define GCT_IGNORE_WHEADER_GUARD_WARNING_END GCTIgnoreClangWarningEnd

//-Wignored-attributes    unknown attribute '%0'
#define GCT_IGNORE_WIGNORED_ATTRIBUTES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wignored-attributes)
#define GCT_IGNORE_WIGNORED_ATTRIBUTES_WARNING_END GCTIgnoreClangWarningEnd

//-Wincomplete-module    header '%0' is included in module '%1' but not listed in module map
#define GCT_IGNORE_WINCOMPLETE_MODULE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wincomplete-module)
#define GCT_IGNORE_WINCOMPLETE_MODULE_WARNING_END GCTIgnoreClangWarningEnd

//-Wincomplete-umbrella    umbrella header for module '%0' does not include header '%1'
#define GCT_IGNORE_WINCOMPLETE_UMBRELLA_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wincomplete-umbrella)
#define GCT_IGNORE_WINCOMPLETE_UMBRELLA_WARNING_END GCTIgnoreClangWarningEnd

//-Winvalid-token-paste    pasting formed '%0', an invalid preprocessing token, DefaultError
#define GCT_IGNORE_WINVALID_TOKEN_PASTE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Winvalid-token-paste)
#define GCT_IGNORE_WINVALID_TOKEN_PASTE_WARNING_END GCTIgnoreClangWarningEnd

//-Wmalformed-warning-check    __has_warning expected option name (e.g. \"-Wundef\")
#define GCT_IGNORE_WMALFOEMED_WARNING_CHECK_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmalformed-warning-check)
#define GCT_IGNORE_WMALFOEMED_WARNING_CHECK_WARNING_END GCTIgnoreClangWarningEnd

//-Wnewline-eof    no newline at end of file
#define GCT_IGNORE_WNEWLINE_EOF_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wnewline-eof)
#define GCT_IGNORE_WNEWLINE_EOF_WARNING_END GCTIgnoreClangWarningEnd

//-Wnull-character    null character ignored
//-Wnull-character    null character(s) preserved in string literal
//-Wnull-character    null character(s) preserved in character literal
#define GCT_IGNORE_WNULL_CHARACTER_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wnull-character)
#define GCT_IGNORE_WNULL_CHARACTER_WARNING_END GCTIgnoreClangWarningEnd

//-Wtrigraphs    ignored trigraph would end block comment
//-Wtrigraphs    trigraph ignored
#define GCT_IGNORE_WTEIGRAPHS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wtrigraphs)
#define GCT_IGNORE_WTEIGRAPHS_WARNING_END GCTIgnoreClangWarningEnd

//-Wundef    %0 is not defined, evaluates to 0
#define GCT_IGNORE_WUNDEF_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wundef)
#define GCT_IGNORE_WUNDEF_WARNING_END GCTIgnoreClangWarningEnd

//-Wunicode    universal character names are only valid in C99 or C++ treating as '\\' followed by identifier
//-Wunicode    \\%0 used with no following hex digits treating as '\\' followed by identifier
//-Wunicode    incomplete universal character name treating as '\\' followed by identifier
//-Wunicode    universal character name refers to a surrogate character
#define GCT_IGNORE_WUNICODE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunicode)
#define GCT_IGNORE_WUNICODE_WARNING_END GCTIgnoreClangWarningEnd

//-Wunknown-pragmas    unknown pragma ignored
//-Wunknown-pragmas    pragma STDC FENV_ACCESS ON is not supported, ignoring pragma
#define GCT_IGNORE_WUNKNOWN_PRAGMAS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunknown-pragmas)
#define GCT_IGNORE_WUNKNOWN_PRAGMAS_WARNING_END GCTIgnoreClangWarningEnd

//-Wunused-macros    macro is not used
#define GCT_IGNORE_WUNUSED_MACROS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wunused-macros)
#define GCT_IGNORE_WUNUSED_MACROS_WARNING_END GCTIgnoreClangWarningEnd


#pragma mark - Parser Warnings

//-Warc-bridge-casts-disallowed-in-nonarc    '%0' casts have no effect when not using ARC
#define GCT_IGNORE_WARC_BRIDGE_CASTS_DISALLOWED_IN_NONARC_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Warc-bridge-casts-disallowed-in-nonarc)
#define GCT_IGNORE_WARC_BRIDGE_CASTS_DISALLOWED_IN_NONARC_WARNING_END GCTIgnoreClangWarningEnd

//-Wattributes    unknown __declspec attribute %0 ignored
#define GCT_IGNORE_WATTRIBUTES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wattributes)
#define GCT_IGNORE_WATTRIBUTES_WARNING_END GCTIgnoreClangWarningEnd

//-Wavailability    'unavailable' availability overrides all other availability information
#define GCT_IGNORE_WAVAILABILITY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wavailability)
#define GCT_IGNORE_WAVAILABILITY_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++11-compat    use of right-shift operator ('') in template argument will require parentheses in C++11
//-Wc++11-compat    'auto' storage class specifier is redundant and incompatible with C++11
#define GCT_IGNORE_WC11_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++11-compat)
#define GCT_IGNORE_WC11_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++98-c++11-compat    'decltype(auto)' type specifier is incompatible with C++ standards before C++1y
#define GCT_IGNORE_WC98_C11_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++98-c++11-compat)
#define GCT_IGNORE_WC98_C11_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++98-compat    range-based for loop is incompatible with C++98
//-Wc++98-compat    alias declarations are incompatible with C++98
//-Wc++98-compat    in-class initialization of non-static data members is incompatible with C++98
//-Wc++98-compat    defaulted function definitions are incompatible with C++98
//-Wc++98-compat    rvalue references are incompatible with C++98
//-Wc++98-compat    reference qualifiers on functions are incompatible with C++98
//-Wc++98-compat    inline namespaces are incompatible with C++98
//-Wc++98-compat    generalized initializer lists are incompatible with C++98
//-Wc++98-compat    trailing return types are incompatible with C++98
//-Wc++98-compat    enumeration types with a fixed underlying type are incompatible with C++98
//-Wc++98-compat    alignof expressions are incompatible with C++98
//-Wc++98-compat    '%0' keyword is incompatible with C++98
//-Wc++98-compat    'decltype' type specifier is incompatible with C++98
//-Wc++98-compat    deleted function definitions are incompatible with C++98
//-Wc++98-compat    consecutive right angle brackets are incompatible with C++98 (use '> >')
//-Wc++98-compat    static_assert declarations are incompatible with C++98
//-Wc++98-compat    scoped enumerations are incompatible with C++98
//-Wc++98-compat    lambda expressions are incompatible with C++98
//-Wc++98-compat    attributes are incompatible with C++98
//-Wc++98-compat    'alignas' is incompatible with C++98
//-Wc++98-compat    noexcept specifications are incompatible with C++98
//-Wc++98-compat    literal operators are incompatible with C++98
//-Wc++98-compat    noexcept expressions are incompatible with C++98
//-Wc++98-compat    'nullptr' is incompatible with C++98
#define GCT_IGNORE_WC98_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++98-compat)
#define GCT_IGNORE_WC98_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wc++98-compat-pedantic    extra '' outside of a function is incompatible with C++98
//-Wc++98-compat-pedantic    extern templates are incompatible with C++98
//-Wc++98-compat-pedantic    commas at the end of enumerator lists are incompatible with C++98
#define GCT_IGNORE_WC98_COMPAT_PEDANTIC_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wc++98-compat-pedantic)
#define GCT_IGNORE_WC98_COMPAT_PEDANTIC_WARNING_END GCTIgnoreClangWarningEnd

//-Wdangling-else    add explicit braces to avoid dangling else
#define GCT_IGNORE_WDANGLING_ELSE_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdangling-else)
#define GCT_IGNORE_WDANGLING_ELSE_WARNING_END GCTIgnoreClangWarningEnd

//-Wdeprecated    Use of 'long' with '__vector' is deprecated
#define GCT_IGNORE_WDEPRECATED_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdeprecated)
#define GCT_IGNORE_WDEPRECATED_WARNING_END GCTIgnoreClangWarningEnd

//-Wdeprecated-declarations    use of C-style parameters in Objective-C method declarations is deprecated
#define GCT_IGNORE_WDEPRECATED_DECLARATIONS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdeprecated-declarations)
#define GCT_IGNORE_WDEPRECATED_DECLARATIONS_WARNING_END GCTIgnoreClangWarningEnd

//-Wdeprecated-register    'register' storage class specifier is deprecated
#define GCT_IGNORE_WDEPRECATED_REGISTER_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdeprecated-register)
#define GCT_IGNORE_WDEPRECATED_REGISTER_WARNING_END GCTIgnoreClangWarningEnd

//-Wduplicate-decl-specifier    duplicate '%0' declaration specifier
#define GCT_IGNORE_WDUPLICATE_DECL_SPECIFIER_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wduplicate-decl-specifier)
#define GCT_IGNORE_WDUPLICATE_DECL_SPECIFIER_WARNING_END GCTIgnoreClangWarningEnd

//-Wextra-semi    extra ';' after member function definition
#define GCT_IGNORE_WEXTRA_SEMI_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wextra-semi)
#define GCT_IGNORE_WEXTRA_SEMI_WARNING_END GCTIgnoreClangWarningEnd

//-Wextra-tokens    "extra tokens at the end of '#pragma omp %0' are ignored
#define GCT_IGNORE_WEXTRA_TOKENS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wextra-tokens)
#define GCT_IGNORE_WEXTRA_TOKENS_WARNING_END GCTIgnoreClangWarningEnd

//-Wgcc-compat    GCC does not allow %0 attribute in this position on a function definition
#define GCT_IGNORE_WGCC_COMPAT_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wgcc-compat)
#define GCT_IGNORE_WGCC_COMPAT_WARNING_END GCTIgnoreClangWarningEnd

//-Wignored-attributes    attribute %0 ignored, because it is not attached to a declaration
#define GCT_IGNORE_WIGNORED_ATTRIBUTES_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wignored-attributes)
#define GCT_IGNORE_WIGNORED_ATTRIBUTES_WARNING_END GCTIgnoreClangWarningEnd

//-Wmicrosoft-exists    dependent %select{__if_not_exists|__if_exists}0 declarations are ignored
#define GCT_IGNORE_WMICROSOFT_EXISTS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmicrosoft-exists)
#define GCT_IGNORE_WMICROSOFT_EXISTS_WARNING_END GCTIgnoreClangWarningEnd

//-Wmissing-selector-name    %0 used as the name of the previous parameter rather than as part of the selector
#define GCT_IGNORE_WMISSING_SELECTOR_NAME_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wmissing-selector-name)
#define GCT_IGNORE_WMISSING_SELECTOR_NAME_WARNING_END GCTIgnoreClangWarningEnd

//-Wsemicolon-before-method-body    semicolon before method body is ignored
#define GCT_IGNORE_WSEMICOLON_BEFORE_METHOD_BODY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsemicolon-before-method-body)
#define GCT_IGNORE_WSEMICOLON_BEFORE_METHOD_BODY_WARNING_END GCTIgnoreClangWarningEnd

//-Wsource-uses-openmp    "unexpected '#pragma omp ...' in program
#define GCT_IGNORE_WSOURCE_USES_OPENMP_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wsource-uses-openmp)
#define GCT_IGNORE_WSOURCE_USES_OPENMP_WARNING_END GCTIgnoreClangWarningEnd

//-Wstatic-inline-explicit-instantiation    ignoring '%select{static|inline}0' keyword on explicit template instantiation
#define GCT_IGNORE_WSTATIC_INLINE_EXPLICIT_INSTANTIATION_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wstatic-inline-explicit-instantiation)
#define GCT_IGNORE_WSTATIC_INLINE_EXPLICIT_INSTANTIATION_WARNING_END GCTIgnoreClangWarningEnd

#define GCT_IGNORE_WPARTIAL_AVAILABILITY_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wpartial-availability)
#define GCT_IGNORE_WPARTIAL_AVAILABILITY_WARNING_END GCTIgnoreClangWarningEnd

#define GCT_IGNORE_WDEPRECATED_DECLARATIONS_WARNING_BEGIN GCTIgnoreClangWarningBegin(-Wdeprecated-declarations)
#define GCT_IGNORE_WDEPRECATED_DECLARATIONS_WARNING_END GCTIgnoreClangWarningEnd

#endif /* GCTFoundationClangConstants_h */
