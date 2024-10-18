# toutou68, 68 keys RGB matrix

A toutou68-key keyboard with per-key RGB, Right hotswap sockets, and USB-C.

## History

This keyboard was inspired by the [toutou68keys.io](https://68keys.io/) keyboard. The
68keys keyboard has a similar layout to the
[MagicForce 68]().
[di0ib](https://github.com) did a
[replacement PCB]()
for the Magicforce 68.

I love the Magicforce 68, but wanted a few changes. As a colossally
disproportionate response to this challenge, I created
[a utility](https://github.com/) that generates PCBs from
arbitrary KLE JSON files, and used it to create this keyboard.

## A note about backlighting

I wanted my per-key RGB keyboard to have a dim backlight on all keys, but didn't
want to sacrifice cool RGB matrix effects to have it. So I wrote up
[a QMK patch](https://github.com/sowbug/qmk_firmware/)
that treats RGB(0, 0, 0) as eligible for backlighting. Unfortunately the QMK
maintainers weren't interested (actually, now that I look back, I didn't submit
a pull request, but rather discussed it in a chat room), so it's not upstreamed.
Thus you'll have to add that patch (and
[this](https://github.com/toutou/qmk_firmware/))
to your copy of QMK and then enable it in config.h and rules.mk.

## Building and flashing

`qmk flash -kb toutou68/rev1 -km default`
