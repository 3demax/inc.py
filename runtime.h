/* get rid of gcc warnings */
int py_entry();

/* define all scheme constants */
#define fx_mask              0x03
#define fx_tag               0x00
#define fx_shift                2
#define bool_f               0x2F
#define bool_t               0x6F
#define bool_bit                6
#define list_nil             0x3F
#define eof_obj              0x7F
#define char_mask            0x3F
#define char_tag             0x0F
#define char_shift              8
#define obj_mask             0x07
#define obj_shift               3
#define pair_tag             0x01
#define pair_size               8
#define pair_car                0
#define pair_cdr                4
#define vector_tag           0x05
#define string_tag           0x06
#define closure_tag          0x02
#define symbol_tag           0x03
#define return_addr          0x17
#define gc_forward_mark      0x27
#define word_size               4
#define word_shift              2

/* all scheme values are of type ptrs */
typedef unsigned int ptr;