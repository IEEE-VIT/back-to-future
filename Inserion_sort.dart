void insertionSort<E>(
  List<E> list, {
  int? begin,
  int? end,
  Comparator<E>? compare,
}) {
  int b, e;
  int n = list.length;

  b = 0;
  e = n;
  if (begin != null && b < begin) {
    b = begin;
  }
  if (end != null && end < e) {
    e = end;
    if (e < 0) e += n;
  }

  if (compare == null) {
    insertionSortDefault(list, b, e);
  } else {
    insertionSortCustom(list, b, e, compare);
  }
}