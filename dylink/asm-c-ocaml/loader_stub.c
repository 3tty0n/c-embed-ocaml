#include <stdio.h>
#include <dlfcn.h>
#include <caml/mlvalues.h>

typedef int (*fun_arg2)(int, int);

typedef int (*fun_arg1)(int);

CAMLprim value call_dlfun_arg1(value filename, value funcname, value arg1) {
  fun_arg1 sym = NULL;
  void *handle = NULL;

  handle = dlopen(String_val(filename), RTLD_LAZY);
  if (handle == NULL) {fprintf(stderr, "error: dlopen\n"); return -1;}

  sym = (fun_arg1)dlsym(handle, String_val(funcname));
  if (sym == NULL) {fprintf(stderr, "error: dlsym\n"); return -1;}

  printf("%d\n", sym(Int_val(arg1)));

  return Val_unit;
}

CAMLprim value call_dlfun_arg2(value filename, value funcname, value arg1, value arg2) {
  fun_arg2 sym = NULL;
  void *handle = NULL;

  handle = dlopen(String_val(filename), RTLD_LAZY);
  if (handle == NULL) {fprintf(stderr, "error: dlopen\n"); return -1;}

  sym = (fun_arg2)dlsym(handle, String_val(funcname));
  if (sym == NULL) {fprintf(stderr, "error: dlsym\n"); return -1;}

  sym(Int_val(arg1), Int_val(arg2));

  return Val_unit;
}
