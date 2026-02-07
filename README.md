# Naming convention
### Entity
  - Contains all properties and the constructor but no other methods
  - Ex: Hero
### Service
  - Business logic of entity
  - Ex: HeroService
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
