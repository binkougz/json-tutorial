#ifndef LEPTJSON_H__ /* include guard */
#define LEPTJSON_H__ /* ends with `_H__` is just a recommendation */

/*
 *  typedef is essentially an alias, as to the compiler, there is 
 *  actually the same type. 
 *   
 *  to eliminate the risk of naming collsion, we normally put the 
 *  project name as prefix of each enum element.
 *   
 *  enum elem are all caps, type and function names are low case instead.
 *   
 *  notice that in c library, they use _t convention as like `size_t`   
 */
typedef enum { 
    LEPT_NULL, 
    LEPT_FALSE, 
    LEPT_TRUE, 
    LEPT_NUMBER, 
    LEPT_STRING, 
    LEPT_ARRAY, 
    LEPT_OBJECT 
} lept_type;

/*
 * for each node in the memory tree, we use the lept_value struct to 
 * represent the value node.
 *
 */
typedef struct {
    lept_type type;
} lept_value;

/*
 * enum of parsing result 
 *
 *
 */
enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR
};

/*
 * json param is an c style string, we are not supposed to change
 * it, so let it const.
 * 
 * the interface is expecting storage is from client code.
 * so v is an pointer of an node struct.
 */
int lept_parse(lept_value* v, const char* json);

/*
 * access the memory tree and returns the json value type
 * as we defined in the beginning.
 */
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
