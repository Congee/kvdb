{
  description = "C++ implementation of a database";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (
      system:
        let
          pkgs = import nixpkgs { inherit system; };
          llvm = pkgs.llvmPackages_14;
          lib = nixpkgs.lib;

        in
          {
            devShell = pkgs.stdenvNoCC.mkDerivation {
              name = "shell";
              nativeBuildInputs = [
                # builder
                # p.gnumake
                # p.bear
                pkgs.cmake  # for discovering libraries
                pkgs.pkg-config
                pkgs.meson
                pkgs.ninja
                # debugger
                # llvm.lldb
                pkgs.gdb

                # XXX: the order of include matters
                pkgs.clang-tools_14
                llvm.clang # clangd
                llvm.libcxxabi

                pkgs.gtest
                pkgs.fmt
                pkgs.tl-expected
              ] ++ lib.optional pkgs.stdenv.isLinux [ llvm.lld ]
              ;

              CPATH = builtins.concatStringsSep ":" [
                (lib.makeSearchPathOutput "dev" "include" [ llvm.libcxx ])
                (lib.makeSearchPath "resource-root/include" [ llvm.clang ])
              ];
              LD_LIBRARY_PATH = lib.strings.makeLibraryPath [ pkgs.fmt ];
            };
          }
    );
}
