/* C extension for ruby_strings.
This file in generated by Rubex. Do not change!
*/
#include <ruby.h>
#include <stdint.h>

VALUE __rubex_f_blank_qmark (int argc, VALUE* argv, VALUE __rubex_arg_self);
VALUE __rubex_f_blank_qmark (int argc, VALUE* argv, VALUE __rubex_arg_self)
{
  VALUE __rubex_arg_string;
  int32_t __rubex_v_i;
  char* __rubex_ptr_s;
  int32_t __rubex_v_length;
  if (argc != 1)
  {
    rb_raise(rb_eArgError, "Need 1 args, not %d", argc);
  }
  __rubex_arg_string=argv[0]  ;
  __rubex_v_i = (int32_t)(0);
  __rubex_ptr_s = (char*)(__rubex_arg_string);
  __rubex_v_length = (int32_t)(RB_TYPE_P(__rubex_arg_string, T_STRING) ? RSTRING_LEN(__rubex_arg_string) : rb_funcall(__rubex_arg_string, rb_intern("size"), 0, NULL));
  while (( __rubex_v_i < __rubex_v_length ))
  {
    if (( __rubex_ptr_s[__rubex_v_i] != ' ' )) 
    {
      return       Qfalse;

    }
    __rubex_v_i = ( __rubex_v_i + 1 );
  }
  return   Qtrue;
}

void Init_ruby_strings (void);
void Init_ruby_strings (void)
{
  rb_define_method(rb_cObject ,"blank?", __rubex_f_blank_qmark, -1);
}
