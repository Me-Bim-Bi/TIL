# ER MODEL:
## 1. Database Model - Phases and Steps:
- Three phases: Conceptual modeling, logical modeling, physical modeling.
- Ten steps:
  - _Conceptual_:
      - 1.Describe the database in text: Update it if there are errors.
      - 2.Identify entities: Highlight key entities in the text.
      - 3.Create a relationship matrix: List all relationships and represent them in a matrix to better define their connections.
      - 4.Draw a simplified ER diagram: Include entities and relationships.
      - 5.Add cardinality: For example, "one movie can have many actors."
      - 6.Define attributes and candidate keys: Answer the question, "What makes a movie unique?" (e.g., movie ID).
  - _Logical_:
      - 7.Convert to a relational model
      - 8.Define primary and foreign keys
  - _Physical_:
      - 9.Create SQL DDL for tables.
      - 10.List the functions the database should support (API).
Diagrams can be created using different tools like paper, draw.io, or Dia Diagram Editor—choose the one that fits best.
Many-to-many relationships must be broken down into separate tables (e.g., a movie with three actors results in three rows).
Document everything as clearly as possible.

## 2.. Conceptual Model:
- **ER Model**:
    - More information can find at: https://www.geeksforgeeks.org/introduction-of-er-model/ 
    - Entities as boxes: Represent objects in the database using **rectangles**.
    - Relationships: Depict connections between entities. Answer key questions: What is the nature of the relationship? (e.g., a person and a house can have relationships like "lives in" or "owns").
What is the cardinality? (e.g., 1-1 means one-to-one, N-M means many-to-many, and N-1 means a person can live in one house, but a house can have multiple residents). Relationships are represented as **diamonds between rectangles.**
    - Total participation: If every entity instance must have a relationship, use **double lines istället för single line to connect the entity to the relationship**.
    - Attributes: Represented as **ovals connected to the corresponding entities**.
    - Unique attributes (candidate keys) **are underlined**.
    - Attributes on relationships: If a relationship has an attribute, it is drawn as **an oval connected to the diamond**. Example: A person lives in a house and has a "move-in year" attribute—this belongs to the "lives in" relationship.
    - Self-referencing relationships: If entities relate to themselves (e.g., people can be friends with other people), represent it with **a diamond above the entity with two connections to itself**.
    - Composite attributes: If an attribute consists of multiple sub-attributes (e.g., a phone number can have a country code and a local number), draw it as **an oval (country code, local number) connected to another oval (phone number)**.
    - Multivalued attributes: If an entity can have multiple values for an attribute (e.g., a person can have multiple phone numbers), represent it with **a double oval**.
    - Derived attributes: Values that are not stored but computed when needed (e.g., age derived from birthdate) are drawn as **an oval with dashed lines**.
    - Weak entity types: Example: An apartment can contain multiple rooms. Room names (e.g., "kitchen," "living room") are not globally unique, but combining them with the apartment number makes them unique.
Indicate weak entities by underlining the apartment number and using **dashed lines for the room name.**
- **Transforming relationships into entities**:
    - Some relationships can be turned into entities.
    - Example: Instead of a many-to-many "watched" relationship between "person" and "movie," introduce a "viewing" entity. This allows tracking details like how many times a person has watched a movie. **Use a rectangle instead of a diamond** to represent the new entity.
- **Extended ER Diagrams**: Subclasses and inheritance: Entities can be specialized into subclasses (e.g., a "person" can be a "student," "teacher," or "astronaut").
- Once the conceptual model is complete, it needs to be translated into the relational model.

## 3. Logical model
- Convert to a relational model: Break down many-to-many relationships.
    - No many-to-many relationships (N:M). 
    - No multi-valued attributes.
    - Only one value in each cell.
    - Each row is unique.
    - No complex relationships.
- Define primary and foreign keys, data type: Adjust the diagram by introducing primary keys (PK) and foreign keys (FK) along with additional attributes.


