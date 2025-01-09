# Nom de l'exécutable
TARGET = hanoi

# Compilateur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -O3

# Répertoires
BUILDDIR = ./bin
INSTALLDIR = $(HOME)/.local/bin

# Fichiers source
SRCS = main.cpp

# Règle par défaut
all: $(BUILDDIR)/$(TARGET)

# Création de l'exécutable dans ./bin
$(BUILDDIR)/$(TARGET): $(SRCS)
	mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -o $(BUILDDIR)/$(TARGET) $(SRCS)

# Exécution
run: $(BUILDDIR)/$(TARGET)
	$(BUILDDIR)/$(TARGET)

# Installation de l'exécutable dans ~/.local/bin
install: $(BUILDDIR)/$(TARGET)
	mkdir -p $(INSTALLDIR)
	cp $(BUILDDIR)/$(TARGET) $(INSTALLDIR)

# Désinstallation de l'exécutable depuis ~/.local/bin
uninstall:
	@if [ -f $(INSTALLDIR)/$(TARGET) ]; then \
		echo "Removing $(INSTALLDIR)/$(TARGET)"; \
		rm $(INSTALLDIR)/$(TARGET); \
	else \
		echo "$(INSTALLDIR)/$(TARGET) not found."; \
	fi

# Nettoyage des fichiers générés
clean:
	rm -rf $(BUILDDIR)/$(TARGET)

# Nettoyage complet (ajout des fichiers temporaires)
distclean: clean
	rm -f *~

.PHONY: all clean distclean run install uninstall
