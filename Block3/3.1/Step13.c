/* Вам доступны:


struct maybe_int64 {
    int64_t value; 
    bool valid; 
};

struct maybe_int64 some_int64(int64_t i);

extern const struct maybe_int64 none_int64;

void maybe_int64_print( struct maybe_int64 i );
struct maybe_int64 maybe_read_int64();
void print_int64(int64_t i)
*/

void interpret_push(struct vm_state* state) {
  stack_push(& state->data_stack, state->ip->as_arg64.arg);
}

void interpret_iread(struct vm_state* state ) {
  stack_push(&(state -> data_stack), read_int64());
}
void interpret_iadd(struct vm_state* state ) {
  struct maybe_int64 el = stack_pop(&(state -> data_stack));
  struct maybe_int64 el2 = stack_pop(&(state -> data_stack));
  if (el.valid && el2.valid) {
      stack_push(&(state -> data_stack), el.value + el2.value);
  } else if (el.valid) {
      stack_push(&(state -> data_stack), el.value);
  } else if (el2.valid) {
      stack_push(&(state -> data_stack), el2.value);
  }
}
void interpret_iprint(struct vm_state* state ) {
  struct maybe_int64 el = stack_pop(&(state -> data_stack));
  if (el.valid) {
      print_int64(el.value);
  }
}

/* Подсказка: можно выполнять программу пока ip != NULL,
    тогда чтобы её остановить достаточно обнулить ip */
void interpret_stop(struct vm_state* state ) {
  state -> ip = NULL;
}


void (*interpreters[])() = {
  [BC_PUSH] = interpret_push,
  [BC_IPRINT] = interpret_iprint,
  [BC_IREAD] = interpret_iread,
  [BC_IADD] = interpret_iadd,
  [BC_STOP] = interpret_stop
};

void interpret(struct vm_state* state) {
    while (state->ip != NULL) {
        (*interpreters[state->ip->opcode])(state);
        if (NULL != state->ip) {
            (state->ip)++;
        }
    }
}
