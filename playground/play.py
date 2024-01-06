import collections, itertools, copy
from typing import List, Dict, Union
Poly = Dict[Union[str, int], int]
Poly = Dict[Union[str, int], int]

def print_return(f):
    def g(*args, **kwargs):
        ret = f(*args, **kwargs)
        print(ret)
        return ret
    return g

def mark_recurse(f):
    def g(*args, **kwargs):
        print("in")
        ret = f(*args, **kwargs)
        print("out")
        return ret
    return g

class Solution:
    def basicCalculatorIV(self, expression: str, evalvars: List[str], evalints: List[int]) -> List[str]:
        scope = {k: v for k, v in zip(evalvars, evalints)}

        # modify a in place! b can be used
        def add(a:Poly, b:Poly, sign_: int):
            for k in b:
                if k not in a: a[k] = b[k]
                else: a[k] += sign_ * b[k]
            return a

        # negate in place, this is intended
        def neg(a: Poly):
            for k in a:
                a[k] *= -1
            return a
        
        # create a new Poly
        def mul(a: Poly, b:Poly):
            c = collections.defaultdict(int)
            for x, y in itertools.product(a, b):
                if x == 1 or y == 1: z = x*y
                else: z = '*'.join(sorted(x.split('*') + y.split('*')))
                c[z] += a[x] * b[y]
            return dict(c)

        # prereq: cur is not None
        # acc, last, op can be None
        @print_return
        def consume_poly(acc, last, cur, op):
            # print(acc, last, cur, op)
            if not acc:
                return cur, copy.deepcopy(cur)
            elif op in '+-':
                if op == '-': neg(cur)
                acc = add(acc, cur, 1)
                return acc, cur
            elif op == '*':
                if last:
                    acc = add(acc, last, -1)
                    last = mul(last, cur)
                else:
                    last = copy.deepcopy(cur)
                acc = add(acc, last, 1)
                return acc, last
            raise("unreachable")

        # parse the current expression starting from idx
        # return a pair (result, the nxt index)
        @mark_recurse
        def parse(expression: str, idx: int, scope: Dict[str, int]):
            cur = idx
            acc = None
            last = None
            op = None
            n = len(expression)
            # print(expression, idx, n)
            while cur < n and expression[cur] != ')':
                # recursive case
                if expression[cur] == '(':
                    # print('in')
                    inner_poly, cur = parse(expression, cur+1, scope)
                    # print('out')
                    acc, last = consume_poly(acc, last, inner_poly, op)
                    continue
                # non recursive, find the next token 
                token_end = cur
                while token_end < n and expression[token_end] not in " )":
                    token_end += 1
                # deal with the token
                token = expression[cur: token_end]
                # print(token)
                this_val = None
                if token in scope:
                    this_val = {1: scope[token]}
                elif token.isdigit():
                    this_val = {1: int(token)}
                elif token in "+-*":
                    op = token
                else:
                    this_val = {token: 1}
                if this_val:
                    acc, last = consume_poly(acc, last, this_val, op)
                # nxt cur
                if token_end < n and expression[token_end] == ')':
                    return acc, token_end + 2
                else:
                    cur = token_end + 1
            return acc, cur+1
        poly = parse(expression, 0, scope)[0]
        ans = []
        for term in sorted(poly.keys(), key=lambda term: (isinstance(term, int), -str(term).count('*'), str(term))):
            if poly[term]: ans.append(str(poly[term]) + ('' if term == 1 else ('*' + term)))
        return ans
        