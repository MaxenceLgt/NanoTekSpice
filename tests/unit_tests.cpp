/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** unit_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Test, Test)
{
    int a = 21;

    cr_assert_eq(a, 21);
}