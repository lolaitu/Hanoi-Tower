# Nom de l'exécutable
TARGET = hanoi

# Compilateur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -O3

# Répertoire pour les fichiers objets
OBJDIR = ./bin

# Répertoire d'installation
PREFIX = $(HOME)/.local
BINDIR = $(PREFIX)/bin

# Fichiers source et objets
SRCS = main.cpp
OBJS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCS))

# Règle par défaut
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilation des fichiers sources dans $(OBJDIR)
$(OBJDIR)/%.o: %.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Installation de l'exécutable
install: $(TARGET)
	install -d $(BINDIR)
	install $(TARGET) $(BINDIR)

# Nettoyage des fichiers générés
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Nettoyage complet (ajout de sauvegardes temporaires)
distclean: clean
	rm -f *~

# Exécution
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean distclean run install
