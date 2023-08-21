def solution(U, L, C):
  # hiz acisindan worst case senaryolar denenmistir ve 1 saniyeden kisa surede sonuc vermistir
  # solution(107401, 107401, [2 for i in range(107401)])
  # solution(0, 0, [0 for i in range(107401)])
  # C = [randint(0,2) for i in range(N)]
  # len(C)-X, X, [randint(0,2) for i in range(N)]  yapisi ile farkli test caseler denenmistir
  if U + L != sum(C):
    return "IMPOSSIBLE"

  N = len(C)
  up = ['0' for i in range(N)]
  bottom = ['0' for i in range(N)]
  imp = False
  U -= C.count(2)
  L -= C.count(2)
  for i, c in zip(range(N), C):
    if c == 0:
      pass
    elif c == 2:
      if U < 0 or L < 0:
        imp = True
        break
      up[i] = '1'
      bottom[i] = '1'
    else:
      if U > 0:
        up[i] = '1'
        U -= 1
      elif L > 0:
        bottom[i] = '1'
        L -= 1
      else:
        imp = True
        break

  if imp:
    return "IMPOSSIBLE"

  s = ""
  return s.join(up)+','+s.join(bottom)

print(solution(2, 2, [2, 0, 2, 0]))