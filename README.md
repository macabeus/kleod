## About this fork (`asmlift-benchmark` branch)

This branch exists to make the [asmlift](https://github.com/macabeus/asmlift) decompiler
benchmark reproducible. It is the upstream
[testyourmine/kleod](https://github.com/testyourmine/kleod) tree at commit
[`64a83ad`](https://github.com/testyourmine/kleod/commit/64a83ad65b52daba92b41328c3220fdd790dd9d9)
("World Map Screen and misc doc", 2026-09-05) — the exact commit the benchmark's functions
were vendored from — plus a minimal integration commit:

- `decomp.yaml` — adds a `tools.asmlift` block pointing asmlift at the project's symbol
  source (`tools.asmlift.elf`): `kleod.elf`, the ELF the normal build already produces
  (names-only, no types-sidecar); no extra build step
- nothing else differs from upstream

To reproduce the benchmark rows: build the project as usual (the ROM must match) — the
built ELF is the symbol source — then follow the per-function scripts published in the
benchmark report.

---

# Klonoa: Empire of Dreams

[![Progress]](https://decomp.dev/testyourmine/kleod/us)

[Progress]: https://decomp.dev/testyourmine/kleod/us.svg?mode=shield

This is a decompilation of Klonoa: Empire of Dreams (USA).

It builds the following ROM:

* [**kleod.gba**](https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=0112) `sha1: a0a298d9dba1ba15d04a42fc2eb35893d1a9569b`

To set up the repository, see [INSTALL.md](INSTALL.md).
