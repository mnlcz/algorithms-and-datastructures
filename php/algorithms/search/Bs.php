<?php

namespace Algorithms\Search;

// Assumes input collection is already sorted
class BinarySearch
{
    public static function find(array $arr, mixed $target): bool
    {
        $search_result = static::search($arr, $target, 0, count($arr) - 1);

        return $search_result['found'];
    }

    public static function findIndex(array $arr, mixed $target): int
    {
        $search_result = static::search($arr, $target, 0, count($arr) - 1);

        return $search_result['index'];
    }

    private static function search(array &$arr, mixed $target, int $start, int $end): array
    {
        $not_found = [
            'found' => false,
            'index' => -1,
        ];

        if ($start > $end) {
            return $not_found;
        }

        $middle = intdiv($start + $end, 2);

        if ($arr[$middle] === $target) {
            return [
                'found' => true,
                'index' => $middle,
            ];
        }

        if ($arr[$middle] > $target) {
            return static::search($arr, $target, $start, $middle - 1);
        }

        if ($arr[$middle] < $target) {
            return static::search($arr, $target, $middle + 1, $end);
        }

        return $not_found;
    }
}
