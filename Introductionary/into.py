from itertools import product

class Expr:
    """Simple propositional logic expression tree."""
    def __init__(self, op, *args):
        self.op = op
        self.args = args

    def __and__(self, other):  # overload &
        return Expr('&', self, other)

    def __or__(self, other):   
        return Expr('|', self, other)

    def __invert__(self):      # overload ~
        return Expr('~', self)

    def __rshift__(self, other):  # overload >>
        return Expr('->', self, other)

    def __eq__(self, other):   # overload ==
        return Expr('<->', self, other)

    def __repr__(self):
        if not self.args:  # symbol
            return self.op
        elif self.op == '~':
            return f"~{self.args[0]}"
        else:
            return f"({self.args[0]} {self.op} {self.args[1]})"

def Symbol(name):
    return Expr(name)


def prop_symbols(expr):
    """Return set of all propositional symbols in expression."""
    if not expr.args:
        return {expr.op}
    symbols = set()
    for arg in expr.args:
        symbols |= prop_symbols(arg)
    return symbols

def extend(model, var, value):
    """Copy model with new assignment {var: value}."""
    new_model = model.copy()
    new_model[var] = value
    return new_model

def pl_true(expr, model):
    """Evaluate expression under truth assignment (model)."""
    if not expr.args:  
        return model.get(expr.op, None)

    if expr.op == '~':
        return not pl_true(expr.args[0], model)

    elif expr.op == '&':
        return pl_true(expr.args[0], model) and pl_true(expr.args[1], model)

    elif expr.op == '|':
        return pl_true(expr.args[0], model) or pl_true(expr.args[1], model)

    elif expr.op == '->': 
        return (not pl_true(expr.args[0], model)) or pl_true(expr.args[1], model)

    elif expr.op == '<->':
        return pl_true(expr.args[0], model) == pl_true(expr.args[1], model)

    else:
        raise ValueError(f"Unknown operator: {expr.op}")



def tt_entails(kb, alpha):
    
    symbols = list(prop_symbols(kb) | prop_symbols(alpha))
    return tt_check_all(kb, alpha, symbols, {})

def tt_check_all(kb, alpha, symbols, model):
    
    if not symbols:
        if pl_true(kb, model):
            return pl_true(alpha, model)
        else:
            return True
    else:
        P, rest = symbols[0], symbols[1:]
        return (tt_check_all(kb, alpha, rest, extend(model, P, True)) and
                tt_check_all(kb, alpha, rest, extend(model, P, False)))


if __name__ == "__main__":
    
    P = Symbol('P')
    Q = Symbol('Q')
    R = Symbol('R')

    # Knowledge base: (P & Q) -> R, and P, and Q
    kb = ((P & Q) >> R) & P & Q

    print("KB entails R?", tt_entails(kb, R))  

    print("KB entails P?", tt_entails(kb, P)) 

    print("KB entails Q?", tt_entails(kb, Q))  

    print("KB entails ~R?", tt_entails(kb, ~R))  
    P11, P12, P21, P22 = map(Symbol, ["P11","P12","P21","P22"])   
    B11, B12, B21, B22 = map(Symbol, ["B11","B12","B21","B22"])   

    kb = (B11 == (P12 | P21))
    kb = kb & (B12 == (P11 | P22))
    
    kb = kb & (B21 == (P11 | P22))
    kb = kb & (B22 == (P12 | P21))

    kb = kb & ~B11

    print("KB entails ~P12 ?", tt_entails(kb, ~P12))
    print("KB entails ~P21 ?", tt_entails(kb, ~P21))