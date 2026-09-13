## About this fork (`asmlift-benchmark` branch)

This branch exists to make the [asmlift](https://github.com/macabeus/asmlift) decompiler
benchmark reproducible. It is the upstream
[testyourmine/kleod](https://github.com/testyourmine/kleod) tree at commit
[`64a83ad`](https://github.com/testyourmine/kleod/commit/64a83ad65b52daba92b41328c3220fdd790dd9d9)
("World Map Screen and misc doc", 2026-09-05) — the exact commit the benchmark's functions
were vendored from — plus a minimal integration commit:

- `decomp.yaml` — adds a `tools.asmlift` block pointing asmlift at the project's symbol
  source (`tools.asmlift.elf`): `kleod-syms.elf`
- `Makefile` — adds the `asmlift-elf` target that derives `kleod-syms.elf`: a copy of the
  built `kleod.elf` with one extra, non-alloc section, the DWARF macro table of a sidecar
  object compiled from the project's own headers. The ROM and `kleod.elf` are untouched
  (the sidecar is never linked into the game), so `make compare` is unaffected. It exists
  because agbcc's `-g` — which already gives asmlift declaration shapes and a signature for
  every function it compiles — cannot record macros, and this project names the GBA I/O
  registers with address-cast macros (`include/gba/io_reg.h`) rather than externs; those
  macros carry the `volatile` qualifier asmlift needs to spell an MMIO access correctly.
- nothing else differs from upstream

To reproduce the benchmark rows: build the project as usual (the ROM must match), then
`make asmlift-elf` — the derived `kleod-syms.elf` is the symbol source — then follow the
per-function scripts published in the benchmark report.

---

# Klonoa: Empire of Dreams

[![Progress]](https://decomp.dev/testyourmine/kleod/us)

[Progress]: https://decomp.dev/testyourmine/kleod/us.svg?mode=shield

This is a decompilation of Klonoa: Empire of Dreams (USA).

It builds the following ROM:

* [**kleod.gba**](https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=0112) `sha1: a0a298d9dba1ba15d04a42fc2eb35893d1a9569b`

To set up the repository, see [INSTALL.md](INSTALL.md).
