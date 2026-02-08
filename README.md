# Naming convention
### Entity
  - Contains all properties and the constructor but no other methods
  - Ex: Hero
### Hub
  - Class which handles action between two or more entities
  - Ex: AttackHub
### Manager
  -Global function with namespace which handles specific entity logic like the 
   creation of an random valued entity. return alltime a unique pointer of the entiy
  - Ex: DiceManager
### Loader 
  - Global function with namespace which loads assets and handle the access to
    there information
  - Ex: ConfigLoader
### Repository
  - Handles crud action of entity to outside source
  - Ex:
### Helper
  - Global function with namespace which contains simple logic
  - Ex: RandomHelper
### Globals
  - Global variables with namespace
  - Ex: WindowGlobals
